/**
 * @file
 * Attaches behaviors for Annotator's tags plugin.
 */

(function ($) {

  'use strict';

  Drupal.behaviors.annotatorTags = {
    attach: function (context, settings) {
      Drupal.Annotator.annotator('addPlugin', 'Tags');
    }
  };

})(jQuery);
