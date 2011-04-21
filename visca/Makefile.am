# the libvisca itself
MAINTAINERCLEANFILES = Makefile.in
lib_LTLIBRARIES = libvisca.la
AM_CFLAGS = -I$(top_srcdir)
EXTRA_DIST = libvisca_avr.c libvisca_win32.c

libvisca_la_LDFLAGS = -version-info @lt_major@:@lt_revision@:@lt_age@

libvisca_la_SOURCES =  \
		libvisca.c 		\
		libvisca.h		\
		libvisca_posix.c

# headers to be installed
pkginclude_HEADERS = libvisca.h

