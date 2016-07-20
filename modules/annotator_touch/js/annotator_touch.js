/**
 * @file
 * Attaches behaviors for Annotator's touch plugin.
 */

(function ($) {

  'use strict';

  Drupal.behaviors.annotatorTouch = {
    attach: function (context, settings) {
      Drupal.Annotator.annotator('addPlugin', 'Touch');
    }
  };

})(jQuery);
