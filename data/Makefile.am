libwacomtabletdir = $(datadir)/libwacom
tablet_files = $(shell find $(top_srcdir)/data -name "*.tablet" -printf "%P\n")
dist_libwacomtablet_DATA =  $(tablet_files)

libwacomstylusdir = $(datadir)/libwacom
stylus_files = $(shell find $(top_srcdir)/data -name "*.stylus" -printf "%P\n")
dist_libwacomstylus_DATA = $(stylus_files)

EXTRA_DIST = \
             wacom.example \
             check-files-in-git.sh \
             check-svg-exists.sh \
             check-data-in-meson.build.sh

SUBDIRS = layouts

noinst_SCRIPTS = check-files-in-git.sh check-svg-exists.sh
EXTRA_DIST += $(noinst_SCRIPTS)

AM_TESTS_ENVIRONMENT=top_srcdir="$(abs_top_srcdir)"; export top_srcdir;
TESTS = $(noinst_SCRIPTS)
