(function ($) {
  Drupal.behaviors.annotatorUnsupported = {
    attach: function (context, settings) {
      Drupal.Annotator.annotator('addPlugin', 'Unsupported');

      if (typeof Drupal.settings.annotator.debug !== "undefined") {
        console.log('Annotator Unsupported plugin has been initialized.');
      }
    }
  };
})(jQuery);