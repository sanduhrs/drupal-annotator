<?php

/**
 * View annotation; Menu callback. 
 */
function annotation_view($entity, $view_mode = 'full', $langcode = NULL) {
  $wrapper = entity_metadata_wrapper('annotation', $entity);
  return $wrapper->view();
}
