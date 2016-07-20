<?php

/**
 * @file
 * HelloWorld Annotator ctools plugin.
 */

/**
 * Class TouchAnnotatorPlugin.
 */
class TouchAnnotatorPlugin extends AnnotatorPlugin {

  /**
   * {@inheritdoc}
   */
  public function setup() {
    drupal_add_js(drupal_get_path('module', 'annotator_touch') . '/js/annotator_touch.js');
  }

}
