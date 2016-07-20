/**
 * @file
 * Attaches behaviors for Annotator's offline plugin.
 */

(function ($) {

  'use strict';

  Drupal.behaviors.annotatorOffline = {
    attach: function (context, settings) {
      Drupal.Annotator.annotator('addPlugin', 'Offline');
    }
  };

})(jQuery);
