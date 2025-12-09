CFLAGS = -Wall -O0 -g
RU = ru/LC_MESSAGES

bin_PROGRAMS=numbergame
pkgdata_DATA = $(RU)/$(PACKAGE).mo

numbergame_SOURCES=src/numbergame.c

AUTOMAKE_OPTIONS = foreign

doxy: Doxyfile.in
	doxygen Doxyfile.in


$(RU)/$(PACKAGE).mo: po/ru/numbergame.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@

gitclean:
	git clean -df
