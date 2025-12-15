#include <check.h>
#include "guesser.h"

#test test1
	int res = toDec("LXIX");
	ck_assert_int_eq(res, 69);

#test test2
	char* res = toRoman(49);
	ck_assert_str_eq(res, "XLIX");
