<?php

/**
 * @file
 * Permissions Annotator Plugin.
 */

$plugin = array(
  'name' => 'permissions',
  'label' => t('Permissions'),
  'module' => 'annotator',
  'handler' => array(
    'class' => 'PermissionsAnnotatorPlugin',
  ),
);
