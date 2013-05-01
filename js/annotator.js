(function ($) {
  Drupal.behaviors.annotator = {
    attach: function (context, settings) {
      Drupal.Annotator = $('.node .content').annotator();
    }
  };
})(jQuery);