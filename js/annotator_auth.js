/**
 * @file
 * Attaches behaviors for Annotator's auth plugin.
 */

(function ($) {

  'use strict';

  Drupal.behaviors.annotatorAuth = {
    attach: function (context, settings) {
      console.log(settings.annotator_auth.token.length);
      Drupal.Annotator.annotator('addPlugin', 'Auth', {
        tokenUrl: settings.annotator_auth.tokenUrl,
        token: settings.annotator_auth.token,
        autoFetch: settings.annotator_auth.autoFetch
      });
    }
  };

})(jQuery);
