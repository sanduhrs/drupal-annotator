<?php

/**
 * @file
 * Markdown Annotator Plugin.
 */

$plugin = array(
  'name' => 'markdown',
  'label' => t('Markdown'),
  'module' => 'annotator',
  'handler' => array(
    'class' => 'MarkdownAnnotatorPlugin',
  ),
);
