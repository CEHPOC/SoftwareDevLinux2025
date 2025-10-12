range: range.c
	cc -O0 -g range.c -o range

clean:
	rm -rf range *.txt

test:
	@gdb -x debug_script_1.gdb --args range 1 12 | grep start > output1.txt
	@gdb -x debug_script_2.gdb --args range -100 100 3 | grep start > output2.txt
	diff output1.txt reference1
	diff output2.txt reference2
