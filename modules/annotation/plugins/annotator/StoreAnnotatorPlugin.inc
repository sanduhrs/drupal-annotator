<?php

/**
 * @file
 * Annotator Store Plugin.
 */

$plugin = array(
  'name' => 'store',
  'label' => t('Store'),
  'module' => 'annotator',
  'handler' => array(
    'class' => 'StoreAnnotatorPlugin',
  ),
);
