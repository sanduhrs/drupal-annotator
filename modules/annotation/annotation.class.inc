<?php

/**
 * @file
 * Annotator annotation entity.
 */

/**
 * Annotation entity class.
 */
class AnnotationClassRevision extends Entity {

  /**
   * AnnotationClassRevision constructor.
   */
  public function __construct(array $values = array(), $entityType = NULL) {
    parent::__construct($values, 'annotation');
  }

  /**
   * {@inheritdoc}
   */
  public function buildContent($view_mode = 'full', $langcode = NULL) {
    $content = array();
    return entity_get_controller($this->entityType)->buildContent($this, $view_mode, $langcode, $content);
  }

  /**
   * {@inheritdoc}
   */
  protected function defaultLabel() {
    $type = entity_test_get_types($this->name);
    return $type->label;
  }

  /**
   * {@inheritdoc}
   */
  protected function defaultUri() {
    return array('path' => 'annotation/' . $this->identifier());
  }

}
