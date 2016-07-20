<?php

/**
 * @file
 * Filter Annotator Plugin.
 */

$plugin = array(
  'name' => 'filter',
  'label' => t('Filter'),
  'module' => 'annotator',
  'handler' => array(
    'class' => 'FilterAnnotatorPlugin',
  ),
);
