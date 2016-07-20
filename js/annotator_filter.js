/**
 * @file
 * Attaches behaviors for Annotator's filter plugin.
 */

(function ($) {

  'use strict';

  Drupal.behaviors.annotatorFilter = {
    attach: function (context, settings) {
      Drupal.Annotator.annotator('addPlugin', 'Filter');
    }
  };

})(jQuery);
