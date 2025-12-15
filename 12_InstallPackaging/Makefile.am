SUBDIRS = src 

RU = ru/LC_MESSAGES
pkgdata_DATA = $(RU)/$(PACKAGE).mo

@DX_RULES@

all-local: doxygen-doc $(man_MANS)

man_MANS = numbergame.1

numbergame.1: src/numbergame
	help2man -N ./$< > numbergame.1

$(RU)/$(PACKAGE).mo: po/ru/numbergame.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@


gitclean:
	git clean -df

CLEANFILES = numbergame.1
