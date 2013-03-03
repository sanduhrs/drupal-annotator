<?php

/**
 * HelloWorld Annotator ctools plugin
 */
class ReadmillAnnotatorPlugin extends AnnotatorPlugin {
  public function setup() {
    drupal_add_library('annotator', 'annotator_readmill', TRUE);
    drupal_add_js(drupal_get_path('module', 'annotator_readmill') . '/js/annotator_readmill.js');
  }
}