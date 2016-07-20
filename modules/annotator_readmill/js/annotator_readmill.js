/**
 * @file
 * Attaches behaviors for Annotator's readmill plugin.
 */

(function ($) {

  'use strict';

  Drupal.behaviors.annotatorReadmill = {
    attach: function (context, settings) {
      Drupal.Annotator.annotator('addPlugin', 'Readmill');
    }
  };

})(jQuery);
