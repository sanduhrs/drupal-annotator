(function ($) {
  Drupal.behaviors.annotatorReadmill = {
    attach: function (context, settings) {
      Drupal.Annotator.annotator('addPlugin', 'Readmill');
    }
  };
})(jQuery);