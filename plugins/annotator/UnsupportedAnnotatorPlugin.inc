<?php

/**
 * @file
 * Unsupported Annotator Plugin.
 */

$plugin = array(
  'name' => 'unsupported',
  'label' => t('Unsupported'),
  'module' => 'annotator',
  'handler' => array(
    'class' => 'UnsupportedAnnotatorPlugin',
  ),
);
