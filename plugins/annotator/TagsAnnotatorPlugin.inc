<?php

/**
 * @file
 * Tags Annotator Plugin.
 */

$plugin = array(
  'name' => 'tags',
  'label' => t('Tags'),
  'module' => 'annotator',
  'handler' => array(
    'class' => 'TagsAnnotatorPlugin',
  ),
);
