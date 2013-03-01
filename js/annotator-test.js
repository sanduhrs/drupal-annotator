(function ($) {
  Annotator.Plugin.HelloWorld = (function() {

    function HelloWorld(element, options) {
      this.element = element;
      this.options = options;
      console.log("Hello World!");
    }

    HelloWorld.prototype.pluginInit = function() {
      console.log("Initialized with annotator: ", this.annotator);
      this.annotator
        .subscribe("beforeAnnotationCreated", function (annotation) {
          console.info("The annotation: %o beforeAnnotationCreated!", annotation)
        })
        .subscribe("annotationCreated", function (annotation) {
          console.info("The annotation: %o annotationCreated!", annotation)
        })
        .subscribe("beforeAnnotationUpdated", function (annotation) {
          console.info("The annotation: %o beforeAnnotationUpdated!", annotation)
        })
        .subscribe("annotationUpdated", function (annotation) {
          console.info("The annotation: %o annotationUpdated!", annotation)
        })
        .subscribe("annotationDeleted", function (annotation) {
          console.info("The annotation: %o annotationDeleted!", annotation)
        })
        .subscribe("annotationEditorShown", function (editor, annotation) {
          console.info("The annotation: %o annotationEditorShown!", annotation)
          console.info("The annotation: %o annotationEditorShown!", editor)
        })
        .subscribe("annotationEditorHidden", function (editor) {
          console.info("The annotation: %o annotationEditorHidden!", editor)
        })
        .subscribe("annotationEditorSubmit", function (editor, annotation) {
          console.info("The annotation: %o annotationEditorSubmit!", annotation)
          console.info("The annotation: %o annotationEditorSubmit!", editor)
        })
        .subscribe("annotationViewerShown", function (viewer, annotations) {
          console.info("The annotation: %o annotationViewerShown!", viewer)
          console.info("The annotation: %o annotationViewerShown!", annotations)
        })
        .subscribe("annotationViewerTextField", function (field, annotation) {
          console.info("The annotation: %o annotationViewerTextField!", field)
          console.info("The annotation: %o annotationViewerTextField!", annotation)
        });
    };

    return HelloWorld;
  })();

  Drupal.behaviors.annotator = {
    attach: function (context, settings) {
      $('.node .content').annotator()
        .annotator('addPlugin', 'Store', {
          prefix: '/annotation/api',
          annotationData: {
            'uri': window.location.href
          },
          loadFromSearch: {
            'limit': 20,
            'uri': window.location.href
          }
        })
        .annotator('addPlugin', 'Tags')
        .annotator('addPlugin', 'Unsupported')
        .annotator('addPlugin', 'Permissions', {
          user: Drupal.settings.annotator.user,
          permissions: {
            'read':   ['admin'],
            'update': ['admin'],
            'delete': ['admin'],
            'admin':  ['admin']
          },
          userId: function (user) {
            if (user && user.uid) { 
              return user.uid;
            }
            return user;
          },
          userString: function (user) {
            if (user && user.name) {
              return user.name;
            }
            return user;
          }
        })
        .annotator('addPlugin', 'Filter', {
          filters: [
            {
              label: 'Tag',
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
            }}
          ]
        })
        .annotator('addPlugin', 'HelloWorld');
    }
  };
})(jQuery);