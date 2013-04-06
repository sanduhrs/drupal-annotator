<?php
function annotator_admin_form($form, &$form_state) {
  $form['annotator_js'] = array(
    '#type' => 'fieldset',
    '#title' => t('Annotator JavaScript settings'),
  );
  $form['annotator_js']['annotator_js_pages'] = array(
    '#type' => 'textarea',
    '#title' => t('Use Annotator on specific pages'),
    '#default_value' => variable_get('annotator_js_pages', 'node/*'),
    '#description' => t("Specify pages by using their paths. Enter one path per line. The '*' character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every personal blog. %front is the front page.", array('%blog' => 'blog', '%blog-wildcard' => 'blog/*', '%front' => '<front>')),
  );
  $form['annotator_js']['annotator_js_selector'] = array(
    '#type' => 'textfield',
    '#title' => t('Annotator page area'),
    '#default_value' => variable_get('annotator_js_selector', 'body'),
    '#description' => t('Use jQuery style selector set HTML area for Annotator. Example: ".content".'),
  );
  return system_settings_form($form);
}

