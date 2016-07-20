<?php

/**
 * @file
 * Auth Annotator Plugin.
 */

$plugin = array(
  'name' => 'auth',
  'label' => t('Auth'),
  'module' => 'annotator',
  'handler' => array(
    'class' => 'AuthAnnotatorPlugin',
  ),
);
