<?php

/**
 * @file
 * Annotator Offline Plugin.
 */

$plugin = array(
  'name' => 'offline',
  'label' => t('Offline'),
  'module' => 'annotator',
  'handler' => array(
    'class' => 'OfflineAnnotatorPlugin',
  ),
);
