<?php

/**
 * @file
 * Annotator HelloWorld Plugin.
 */

$plugin = array(
  'name' => 'helloworld',
  'label' => t('HelloWorld'),
  'module' => 'annotator',
  'handler' => array(
    'class' => 'HelloWorldAnnotatorPlugin',
  ),
);
