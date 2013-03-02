<?php

/**
 * Annotator ctools plugin
 */
class I18nAnnotatorPlugin extends AnnotatorPlugin {
  public function __construct() {
    $initialized = variable_get('annotator_locales_initialized', FALSE);
    if (!$initialized &&
        module_exists('locale')) {
      $this->initializeLocales();
      variable_set('annotator_locales_initialized', TRUE);
    }
  }

  public function setup() {
    global $language;
    
    $element = array(
      '#tag' => 'link',
      '#attributes' => array(
        'href' => base_path() . drupal_get_path('module', 'annotator') . '/locale/' . $language->language . '.json',
        'rel' => 'gettext',
        'type' => 'application/json',
      ),
    );
    drupal_add_html_head($element, 'jsgettext');
  }
}