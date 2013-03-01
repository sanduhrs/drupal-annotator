(function ($) {
  Drupal.behaviors.annotator = {
    attach: function (context, settings) {
      Drupal.Annotator = $('.node .content').annotator();

      if (typeof Drupal.settings.annotator.debug !== "undefined") {
        console.log('jQuery Annotator has been initialized.');
      }
    }
  };
})(jQuery);