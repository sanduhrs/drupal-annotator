<?php

/**
 * HelloWorld Annotator ctools plugin
 */
class HelloWorldAnnotatorPlugin extends AnnotatorPlugin {
  public function setup() {
    drupal_add_js(drupal_get_path('module', 'annotator_helloworld') . '/js/annotator_helloworld.js');
  }
}