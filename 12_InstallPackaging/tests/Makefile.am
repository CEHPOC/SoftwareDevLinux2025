TESTS = tran
check_PROGRAMS = tran

%.c: %.ck
	checkmk $< > $@
	echo $(CHECK_CFLAGS)
AM_CFLAGS = -I$(top_builddir)/src @CHECK_CFLAGS@
LDADD = $(top_builddir)/src/libguesser.la @CHECK_LIBS@
