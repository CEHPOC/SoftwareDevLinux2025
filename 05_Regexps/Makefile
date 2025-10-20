esub: esub.c
	cc -O0 -g esub.c -o esub

clean:
	rm esub *.out

test:
	./esub
	./esub "a(b" ab ab
	./esub ab "a\1b" ab
	./esub "(b)(a)" "BA\2\1" ababac
	./esub "(b)(a)" "BA\2\1\7" ababac
	./esub "(a)b(c)d(e)" "<\3\2\1>" _abcdef_
	./esub "(b)(a)" "BA\2\1" ababac >> esub.out
	./esub "(a)b(c)d(e)" "<\3\2\1>" _abcdef_ >> esub.out
	./esub "(c)de" "\1_\1" abcde >> esub.out
	echo 'ababac' | sed -E 's/(b)(a)/BA\2\1/' >> sed.out
	echo '_abcdef_' | sed -E 's/(a)b(c)d(e)/<\3\2\1>/' >> sed.out
	echo 'abcde' | sed -E 's/(c)de/\1_\1/' >> sed.out
	diff -s esub.out sed.out

