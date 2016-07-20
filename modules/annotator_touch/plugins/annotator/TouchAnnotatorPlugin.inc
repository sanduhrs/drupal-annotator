<?php

/**
 * @file
 * Annotator Touch Plugin.
 */

$plugin = array(
  'name' => 'touch',
  'label' => t('Touch'),
  'module' => 'annotator',
  'handler' => array(
    'class' => 'TouchAnnotatorPlugin',
  ),
);
