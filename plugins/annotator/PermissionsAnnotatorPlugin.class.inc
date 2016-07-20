<?php

/**
 * @file
 * Permissions Annotator Plugin.
 */

/**
 * Annotator ctools plugin.
 */
class PermissionsAnnotatorPlugin extends AnnotatorPlugin {

  /**
   * Settings form for PermissionsAnnotatorPlugin.
   */
  public function settingsForm() {
    $defaults = $this->settings();
    $form['showViewPermissionsCheckbox'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show view permissions Checkbox'),
      '#default_value' => $defaults['showViewPermissionsCheckbox'],
    );
    $form['showEditPermissionsCheckbox'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show edit permissions Checkbox'),
      '#default_value' => $defaults['showEditPermissionsCheckbox'],
    );
    return $form;
  }

  /**
   * Setttings for PermissionsAnnotatorPlugin.
   */
  public function settings($defaults = array()) {
    $defaults = array(
      'showViewPermissionsCheckbox' => FALSE,
      'showEditPermissionsCheckbox' => FALSE,
    );
    return parent::settings($defaults);
  }

  /**
   * Set up PermissionsAnnotatorPlugin.
   */
  public function setup() {
    $settings = $this->permissions();
    drupal_add_js(array('annotator_permissions' => (array) $settings), 'setting');
    drupal_add_js(drupal_get_path('module', 'annotator') . '/js/annotator_permissions.js');
  }

  /**
   * Set permissions.
   */
  public function permissions($annotation = NULL) {
    global $user;

    $own = FALSE;
    // Set the right permission for new annotations.
    if (!isset($annotation)) {
      $own = user_access('edit own annotations');
    }
    // Set the right permission for existing annotations.
    elseif (isset($annotation->uid)) {
      $own = user_access('edit own annotations') && ($annotation->uid == $user->uid);
    }

    $settings = $this->settings();
    $settings['user'] = array(
      'uid' => $user->uid,
      'name' => format_username($user),
      'roles' => array_keys($user->roles),
    );

    $roles = user_roles(FALSE, 'administer annotations');
    $settings['permissions']['admin'] = array(
      'user' => array(),
      'roles' => array_keys($roles),
    );
    $roles = user_roles(FALSE, 'edit any annotations');
    $settings['permissions']['delete'] = array(
      'user' => array(
        $own ? $user->uid : NULL,
      ),
      'roles' => array_keys($roles),
    );
    $roles = user_roles(FALSE, 'view annotations');
    $settings['permissions']['read'] = array(
      'user' => array(),
      'roles' => array_keys($roles),
    );
    $roles = user_roles(FALSE, 'edit any annotations');
    $settings['permissions']['update'] = array(
      'user' => array(
        $own ? $user->uid : NULL,
      ),
      'roles' => array_keys($roles),
    );
    return $settings;
  }

}
