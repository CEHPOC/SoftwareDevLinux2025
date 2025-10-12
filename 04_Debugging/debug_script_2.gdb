set pagination off
set logging enabled on
tty /dev/null

set $i = 0
b 62 if ($i>=28 && $i<36)
b 62 if !($i>=28 && $i<36)
command 1
	silent
	print I
	set $i = $i + 1
	cont
end
command 2
	silent
	set $i = $i + 1
	cont
end

run
quit
