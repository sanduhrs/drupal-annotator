(function ($) {
  Drupal.behaviors.annotatorFilter = {
    attach: function (context, settings) {
      Drupal.Annotator.annotator('addPlugin', 'Filter', {
        filters: [
          {
            label: Drupal.t('Quote'),
            property: 'quote'
          },
          {
            label: Drupal.t('Tag'),
            property: 'tags',
            isFiltered: function (input, tags) {
              if (input && tags && tags.length) {
                var keywords = input.split(/\s+/g);
                for (var i = 0; i < keywords.length; i += 1) {
                  for (var j = 0; j < tags.length; j += 1) {
                    if (tags[j].indexOf(keywords[i]) !== -1) {
                      return true;
                    }
                  }
                }
              }
              return false;
            }
          }
        ]
      });

      if (typeof Drupal.settings.annotator.debug !== "undefined") {
        console.log('Annotator Filter plugin has been initialized.');
      }
    }
  };
})(jQuery);