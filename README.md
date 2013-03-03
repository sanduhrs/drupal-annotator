# README

Annotator is a [Drupal](http://drupal.org/ "Drupal.org") module to integrate
[Open Knowledge Foundation's Annotator](http://okfnlabs.org/annotator/ "Annotator")
project.

## Features

* Provides an entity based backend-store
* Support for I18N
* Support for the Store plugin
* Support for the Permissions plugin
* Support for the Auth plugin
* Support for the Tags plugin
* Support for the Unsupported plugin
* Support for the Markdown plugin
* Support for the Filter plugin
* Integrates with Ctools plugins

## Dependencies

* [Ctools](http://drupal.org/project/ctools "Ctools")
* [Entity API](http://drupal.org/project/entity "Entity API")
* [jQuery Update v1.7](http://drupal.org/project/jquery_update "jQuery Update")

## Localization

The current translation is found on [Transifex](https://www.transifex.com/projects/p/annotator/ "Transifex").
To generate JSON from the PO files you can use [Javascript Gettext](http://jsgettext.berlios.de/ "Javascript Gettext")

`sudo apt-get install perl liblocale-po-perl`

to be able to use

`po2json -p lang.po > lang.json`

## License
Copyright (c) 2013 Stefan Auditor
Licensed under the GNU, Library, General, Public, License licenses.
