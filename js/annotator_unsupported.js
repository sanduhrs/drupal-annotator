/**
 * @file
 * Attaches behaviors for Annotator's unsupported plugin.
 */

(function ($) {

  'use strict';

  Drupal.behaviors.annotatorUnsupported = {
    attach: function (context, settings) {
      Drupal.Annotator.annotator('addPlugin', 'Unsupported');
    }
  };

})(jQuery);
