CFLAGS = -Wall -O0 -g
RU = ru/LC_MESSAGES

bin_PROGRAMS=numbergame
pkgdata_DATA = $(RU)/$(PACKAGE).mo

numbergame_SOURCES=src/numbergame.c

AUTOMAKE_OPTIONS = foreign

@DX_RULES@

man_MANS = docs/man/man1/numbergame.1

all-local: $(man_MANS)

docs/man/man1/numbergame.1: numbergame
	mkdir -p docs/man/man1
	help2man -N ./$< > docs/man/man1/$<.1

install-data-local:
	mkdir -p $(DESTDIR)/$(docdir)
	cp -a docs/html $(DESTDIR)/$(docdir)
	cp -a docs/man $(DESTDIR)/$(docdir)

$(RU)/$(PACKAGE).mo: po/ru/numbergame.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@

gitclean:
	git clean -df
