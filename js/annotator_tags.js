(function ($) {
  Drupal.behaviors.annotatorTags = {
    attach: function (context, settings) {
      Drupal.Annotator.annotator('addPlugin', 'Tags');

      if (typeof Drupal.settings.annotator.debug !== "undefined") {
        console.log('Annotator Tags plugin has been initialized.');
      }
    }
  };
})(jQuery);