<?php

/**
 * HelloWorld Annotator ctools plugin
 */
class TouchAnnotatorPlugin extends AnnotatorPlugin {
  public function setup() {
    drupal_add_js(drupal_get_path('module', 'annotator_touch') . '/js/annotator_touch.js');
  }
}