# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
import textwrap
import json
import os
import sys
sys.path.insert(0, os.path.abspath(os.path.join('..', 'exts')))

schwurbler_version = json.load(open('../library.json'))['version']
from sphinx.builders.html import StandaloneHTMLBuilder
import subprocess

rst_epilog = """
.. |SCHWURBLERCONTROLLERS_VERSION| replace:: %s
""" % schwurbler_version

# -- Project information -----------------------------------------------------

project = 'Schwurbler'
copyright = '2020, Manuel Braun'
author = 'Manuel Braun'

# The full version, including alpha/beta/rc tags
release = '1.0.3'


# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [
    'breathe',
    'exhale',
    'notfound.extension',
    'sphinx.ext.autodoc',
    'sphinx.ext.autosummary',
    'sphinx.ext.coverage',
    'sphinx.ext.intersphinx',
    'sphinx.ext.inheritance_diagram',
    'sphinx.ext.mathjax',
    'sphinx.ext.todo',
    'sphinx.ext.viewcode',
    'sphinx_git'
]

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']

# -- breathe configuration ---------------------------------------------------

# Setup the breathe extension
breathe_projects = {
    "Schwurbler": "./doxyoutput/xml"
}
breathe_default_project = "Schwurbler"

# -- exhale configuration ---------------------------------------------------

exhale_args = {
    # These arguments are required
    "containmentFolder":     "./controllers",
    "rootFileName":          "library_root.rst",
    "rootFileTitle":         "SchwurblerControllers",
    "afterTitleDescription": textwrap.dedent('''
.. hint::

    Here you can find the SchwurblerControllers Library used
    to control the inputs for the Schwurbler!
    '''),
    # "afterHierarchyDescription": textwrap.dedent('''
    #     Below you can see all existing controllers for inputs supported by the
    #     Schwurbler devices.
    # '''),
    "alwaysColorize": True,
    "fullApiSubSectionTitle": "All controllers",
    "fullToctreeMaxDepth": 5,
    "doxygenStripFromPath":  "..",
    # Suggested optional arguments
    "createTreeView":        True,
    # TIP: if using the sphinx-bootstrap-theme, you need
    # "treeViewIsBootstrap": True,
    "exhaleExecutesDoxygen": True,
    "exhaleDoxygenStdin": textwrap.dedent('''
         EXTRACT_ALL = YES
        SOURCE_BROWSER = YES
        EXTRACT_STATIC = YES
        OPTIMIZE_OUTPUT_FOR_C  = YES
        HIDE_SCOPE_NAMES = YES
        QUIET = YES
        INPUT = ../include ../src
        FILE_PATTERNS = *.cpp *.h
        EXAMPLE_RECURSIVE = YES
        GENERATE_TREEVIEW = YES
    ''')
    #../examples/ControlButton
}

# Tell sphinx what the primary language being documented is.
primary_domain = 'cpp'

# Tell sphinx what the pygments highlight language should be.
highlight_language = 'cpp'


# -- Options for HTML output -------------------------------------------------

# -- Theme configuration ---------------------------------------------------

html_theme = 'alabaster'
try:
    import sphinx_rtd_theme
    html_theme = "sphinx_rtd_theme"
    del sphinx_rtd_theme
except ModuleNotFoundError:
    pass

if html_theme == "sphinx_rtd_theme":
    html_theme_options = {
        'canonical_url': '',
        'display_version': False,
        'prev_next_buttons_location': 'bottom',
        'style_external_links': True,
        'logo_only': False,

        # Toc options
        'collapse_navigation': True,
        'sticky_navigation': True,
        'navigation_depth': 2,
        'includehidden': False,
        'titles_only': False
    }

    extensions.append('sphinx_rtd_theme')

html_logo = '_static/hscommunity_logo.jpg'
github_url = 'https://github.com/mommel/hs-lr-midi-schwurbler'
pygments_style = 'sphinx'

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['_static']
