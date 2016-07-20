<?php

/**
 * @file
 * Annotator Readmill Plugin.
 */

$plugin = array(
  'name' => 'readmill',
  'label' => t('Readmill'),
  'module' => 'annotator',
  'handler' => array(
    'class' => 'ReadmillAnnotatorPlugin',
  ),
);
