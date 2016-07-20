/**
 * @file
 * Attaches behaviors for Annotator's markdown plugin.
 */

(function ($) {

  'use strict';

  Drupal.behaviors.annotatorMarkdown = {
    attach: function (context, settings) {
      Drupal.Annotator.annotator('addPlugin', 'Markdown');
    }
  };

})(jQuery);
