set pagination off
set logging enabled on
tty /dev/null
b 62 if I.iter % 5 == 0
command 1
	silent
	print I
	cont
end

run
quit
