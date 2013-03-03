(function ($) {
  Drupal.behaviors.annotatorOffline = {
    attach: function (context, settings) {
      Drupal.Annotator.annotator('addPlugin', 'Offline');
    }
  };
})(jQuery);