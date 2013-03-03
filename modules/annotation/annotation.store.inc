<?php

/**
 * Annotator Store API
 * @see https://github.com/okfn/annotator/wiki/Storage
 *
 * TODO: API permissions
 */

define('ANNOTATOR_VERSION', '2.0.0');
define('ANNOTATOR_SCHEMA_VERSION', 'v1.0');

/**
 * Annotation API main endpoint
 */
function annotation_endpoint($id = NULL) {
  $output = array();
  $method = $_SERVER['REQUEST_METHOD'];

  switch ($method) {
    case 'GET':
      if (isset($id) && is_numeric($id)) {
        $output = annotation_api_read($id);
      }
      else {
        $output = annotation_api_index();
      }
      break;
    case 'POST':
      $output = annotation_api_create();
      break;
    case 'PUT':
      $output = annotation_api_update($id);
      break;
    case 'DELETE':
      $output = annotation_api_destroy($id);
      break;
  }
}

/**
 * Annotation API root
 */
function annotation_api() {
  drupal_json_output(
    array(
      'name' => 'Annotator Store API',
      'version' => ANNOTATOR_VERSION,
    )
  );
}

/**
 * Annotation API index
 */
function annotation_api_index() {
  $records = annotation_load_multiple(FALSE);
  foreach ($records as $rid => $record) {
    $records[$rid] = annotation_api_entity_prepare($record, 'read');
  }

  // Send response
  drupal_json_output(array_values($records));
}

/**
 * Annotation API create
 */
function annotation_api_create() {
  global $user;

  $entity = annotation_api_from_stdin();
  $entity->user = $user->uid;
  $entity->created = REQUEST_TIME;
  $entity->updated = REQUEST_TIME;

  $entity = annotation_api_entity_prepare($entity, 'create');
  annotation_save($entity);

  // Send response
  drupal_json_output($entity);
}

/**
 * Annotation API read
 */
function annotation_api_read($id) {
  $record = annotation_load($id);
  $record = array_shift($record);
  $record = annotation_api_entity_prepare($record, 'read');

  // Send response
  drupal_json_output($record);
}

/**
 * Annotation API update
 */
function annotation_api_update($id) {
  global $user;

  $entity = annotation_api_from_stdin();
  $entity->updated = REQUEST_TIME;

  $entity = annotation_api_entity_prepare($entity, 'update');
  annotation_save($entity);

  // Send response
  drupal_json_output($entity);
}

/**
 * Annotation API destroy
 */
function annotation_api_destroy($id) {
  annotation_delete($id);

  // Send response
  drupal_add_http_header('Status', '204 NO CONTENT');
  drupal_json_output(NULL);
}

/**
 * Annotation API search
 */
function annotation_api_search() {
  $total = 0;
  $records = array();

  $limit   = isset($_GET['limit'])   ? $_GET['limit']      : 20;
  $offset  = isset($_GET['offset'])  ? $_GET['offset']     : 0;

  $id      = isset($_GET['id'])      ? $_GET['id']         : NULL;
  $user    = isset($_GET['user'])    ? $_GET['user']       : NULL;
  $created = isset($_GET['created']) ? $_GET['created']    : NULL;
  $updated = isset($_GET['updated']) ? $_GET['updated']    : NULL;
  $text    = isset($_GET['text'])    ? $_GET['text']       : NULL;
  $quote   = isset($_GET['quote'])   ? $_GET['quote']      : NULL;
  $uri     = isset($_GET['uri'])     ? $_GET['uri']        : NULL;
  $tags    = isset($_GET['tags'])    ? explode(',', $tags) : NULL;

  // Initiate query
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'annotation');

  // Add conditions to query
  if ($id) {
    $query->propertyCondition('uri', $id);
  }
  if ($user) {
    // Use uid instead of user
    $query->propertyCondition('uid', $user);
  }
  if ($created) {
    $query->propertyCondition('created', $created);
  }
  if ($updated) {
    $query->propertyCondition('updated', $updated);
  }
  if ($text) {
    $query->propertyCondition('text', $text, 'LIKE');
  }
  if ($quote) {
    $query->propertyCondition('quote', $quote, 'LIKE');
  }
  if ($uri) {
    $query->propertyCondition('uri', $uri);
  }
  if (is_array($tags)) {
    foreach($tags as $tag) {
      $query->propertyCondition('tags', '"' . $tag . '"', 'LIKE');
    }
  }

  // Get the total
  $count_query = clone $query;
  $total = $count_query->count()->execute();
  
  // Set query range
  if ($limit > 0) {
    $query->range($offset, $limit);
  }
  $result = $query->execute();

  if (isset($result['annotation'])) {
    $annotation_items_nids = array_keys($result['annotation']);
    $records = annotation_load_multiple($annotation_items_nids);
  }

  foreach ($records as $rid => $record) {
    $records[$rid] = annotation_api_entity_prepare($record, 'read');
  }

  $output = array(
    'total' => $total,
    'rows' => array_values($records),
  );
  drupal_json_output($output);
}

/**
 * Get data from stdin
 * @see http://php.net/manual/en/features.file-upload.put-method.php
 */
function annotation_api_from_stdin() {
  $json = '';
  // PUT data comes in on the stdin stream
  $put = fopen('php://input', 'r');
  // Read the data 1 KB at a time and write to the file
  while ($chunk = fread($put, 1024)) {
    $json .= $chunk;
  }
  fclose($put);

  $entity = (object) drupal_json_decode($json);
  $entity = annotation_api_entity_prepare($entity);
  return $entity;
}

/**
 * Prepare entity for api usage
 */
function annotation_api_entity_prepare($entity, $op) {
  switch($op) {
    case 'read':
      $account = user_load($entity->uid);
      $entity->user = array(
        'uid' => $account->uid,
        'name' => $account->name,
        'roles' => array_values($account->roles),
      );
      unset($entity->uid);
      break;
    case 'create':
      $entity->uid = $entity->user;
      unset($entity->user);
      break;
    case 'update':
      $entity->uid = $entity->user;
      unset($entity->user);
      break;
  }
  return $entity;
}
