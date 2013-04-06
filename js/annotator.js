(function ($) {
  Drupal.behaviors.annotator = {
    attach: function (context, settings) {
      Drupal.Annotator = $(Drupal.settings.annotator.target).annotator();
      Drupal.Annotator.annotator('addPlugin', 'Store', {
        // The endpoint of the store on your server.
        prefix: '/annotator/api',
        // Attach the uri of the current page to all annotations to allow search.
        annotationData: {
          'uri': document.URL
        },
        // This will perform a "search" action rather than "read" when the plugin
        // loads. Will request the last 20 annotations for the current url.
        // eg. /store/endpoint/search?limit=20&uri=http://this/document/only
        loadFromSearch: {
          'limit': 0,
          'uri': document.URL
        }
      });
    }
  };
})(jQuery);
