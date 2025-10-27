all: move generate
move: 
	cc -O0 -g move.c -o move
	cc -shared -fPIC rem.c -o rem.so
generate:
	echo "abcde" > input.txt
	echo "WARNING" > input_PROTECT.txt
clean:
	rm *.txt rem.so move
test:
	strace -e openat -e fault=openat:error=ENOENT:when=3 ./move input.txt output.txt
	strace -e openat -e fault=openat:error=EACCES:when=3 ./move input.txt output.txt
	strace -e openat -e fault=openat:error=EBUSY:when=3 ./move input.txt output.txt
	LD_PRELOAD=./rem.so ./move input.txt output.txt | stat input.txt
	LD_PRELOAD=./rem.so ./move input_PROTECT.txt output.txt | stat input_PROTECT.txt
