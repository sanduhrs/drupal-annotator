<?php

/**
 * Annotator ctools plugin
 */
class I18nAnnotatorPlugin extends AnnotatorPlugin {
  public function setup() {
    global $language;
    error_log(print_r($language, true));
    drupal_add_js(drupal_get_path('module', 'annotator') . '/js/annotator_i18n.js');
  }
}