<?php

/**
 * @file
 * Annotator Plugin.
 */

/**
 * Annotator ctools plugin.
 */
class AnnotatorPlugin {

  /**
   * Constructor for AnnotatorPlugin.
   */
  public function __construct($plugin = array()) {
    foreach ($plugin as $name => $attribute) {
      if (is_string($attribute)) {
        $this->{$name} = $attribute;
      }
    }
  }

  /**
   * Settings form for AnnotatorPlugin.
   */
  public function settingsForm() {
    return NULL;
  }

  /**
   * Get settings for AnnotatorPlugin.
   */
  public function settings($defaults = array()) {
    $stored = variable_get('annotator_' . $this->name, array());
    return array_merge($defaults, $stored);
  }

  /**
   * Set up AnnotatorPlugin.
   */
  public function setup() {}

  /**
   * Alter AnnotatorPlugin.
   */
  public function alter(&$annotation, $op) {}

}
