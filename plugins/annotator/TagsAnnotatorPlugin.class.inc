<?php

/**
 * @file
 * Tags Annotator Plugin.
 */

/**
 * Annotator ctools plugin.
 */
class TagsAnnotatorPlugin extends AnnotatorPlugin {

  /**
   * Set up TagsAnnotatorPlugin.
   */
  public function setup() {
    drupal_add_js(drupal_get_path('module', 'annotator') . '/js/annotator_tags.js');
  }

}
