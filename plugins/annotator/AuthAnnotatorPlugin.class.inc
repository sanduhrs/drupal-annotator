<?php

/**
 * @file
 * Auth Annotator Plugin.
 */

/**
 * Annotator ctools plugin.
 */
class AuthAnnotatorPlugin extends AnnotatorPlugin {

  /**
   * Settings form for AuthAnnotatorPlugin.
   */
  public function settingsForm() {
    $defaults = $this->settings();
    $form['tokenUrl'] = array(
      '#type' => 'textfield',
      '#title' => t('Token URL'),
      '#default_value' => $defaults['tokenUrl'],
    );
    $form['token'] = array(
      '#type' => 'textfield',
      '#title' => t('Token'),
      '#default_value' => $defaults['token'],
    );
    $form['autoFetch'] = array(
      '#type' => 'checkbox',
      '#title' => t('Token'),
      '#default_value' => $defaults['autoFetch'],
    );
    return $form;
  }

  /**
   * Get settings for AuthAnnotatorPlugin.
   */
  public function settings($defaults = array()) {
    $defaults = array(
      'tokenUrl' => '/auth/token',
      'token' => NULL,
      'autoFetch' => TRUE,
    );
    return parent::settings($defaults);
  }

  /**
   * Set up AuthAnnotatorPlugin.
   */
  public function setup() {
    $settings = $this->settings();
    drupal_add_js(array('annotator_auth' => (array) $settings), 'setting');
    drupal_add_js(drupal_get_path('module', 'annotator') . '/js/annotator_auth.js');
  }

}
