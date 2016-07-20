/**
 * @file
 * Attaches behaviors for Annotator's HelloWorld plugin.
 */

(function ($) {

  'use strict';

  Annotator.Plugin.HelloWorld = (function () {

    function HelloWorld(element, options) {
      this.element = element;
      this.options = options;
    }

    HelloWorld.prototype.pluginInit = function () {
      console.log("Initialized with annotator: ", this.annotator);

      this.annotator
        .subscribe("beforeAnnotationCreated", function (annotation) {
          console.info("beforeAnnotationCreated: %o beforeAnnotationCreated!", annotation)
        })
        .subscribe("annotationCreated", function (annotation) {
          console.info("annotationCreated: %o annotationCreated!", annotation)
        })
        .subscribe("beforeAnnotationUpdated", function (annotation) {
          console.info("beforeAnnotationUpdated: %o beforeAnnotationUpdated!", annotation)
        })
        .subscribe("annotationUpdated", function (annotation) {
          console.info("annotationUpdated: %o annotationUpdated!", annotation)
        })
        .subscribe("annotationDeleted", function (annotation) {
          console.info("annotationDeleted: %o annotationDeleted!", annotation)
        })
        .subscribe("annotationEditorShown", function (editor, annotation) {
          console.info("annotationEditorShown: %o annotationEditorShown!", editor)
          console.info("annotationEditorShown: %o annotationEditorShown!", annotation)
        })
        .subscribe("annotationEditorHidden", function (editor) {
          console.info("annotationEditorHidden: %o annotationEditorHidden!", editor)
        })
        .subscribe("annotationEditorSubmit", function (editor, annotation) {
          console.info("annotationEditorSubmit: %o annotationEditorSubmit!", editor)
          console.info("annotationEditorSubmit: %o annotationEditorSubmit!", annotation)
        })
        .subscribe("annotationViewerShown", function (viewer, annotations) {
          console.info("annotationViewerShown: %o annotationViewerShown!", viewer)
          console.info("annotationViewerShown: %o annotationViewerShown!", annotations)
        })
        .subscribe("annotationViewerTextField", function (field, annotation) {
          console.info("annotationViewerTextField: %o annotationViewerTextField!", field)
          console.info("annotationViewerTextField: %o annotationViewerTextField!", annotation)
        });
    };

    return HelloWorld;
  })();

  Drupal.behaviors.annotatorHelloWorld = {
    attach: function (context, settings) {
      Drupal.Annotator.annotator('addPlugin', 'HelloWorld');
    }
  };

})(jQuery);
