CFLAGS = -Wall -O0 -g

lib_LTLIBRARIES = libguesser.la
libguesser_la_LDFLAGS = -version-info 1:0:0
libguesser_la_SOURCES = guesser.c guesser.h

bin_PROGRAMS = numbergame
numbergame_SOURCES = numbergame.c

numbergame_LDADD = libguesser.la

include_HEADERS = guesser.h
