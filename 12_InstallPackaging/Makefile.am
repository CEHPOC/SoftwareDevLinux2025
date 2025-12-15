CFLAGS = -Wall -O0 -g
RU = ru/LC_MESSAGES

bin_PROGRAMS=numbergame
pkgdata_DATA = $(RU)/$(PACKAGE).mo

numbergame_SOURCES=src/numbergame.c

@DX_RULES@

all-local: doxygen-doc $(man_MANS)

man_MANS = numbergame.1

numbergame.1: numbergame
	help2man -N ./$< > $<.1

$(RU)/$(PACKAGE).mo: po/ru/numbergame.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@


gitclean:
	git clean -df

CLEANFILES = numbergame.1
