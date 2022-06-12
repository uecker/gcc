/*
 * { dg-do compile }
 * { dg-options "-fno-tag-compat" }
 */




struct foo {
	char x[10];
} x;


void f(void)
{
	struct foo { char x[_Generic(&x, struct foo*: 1, default: 10)]; };

	struct foo z;
	_Static_assert(10 == sizeof(z.x), "");
}

enum A { B = 7 } y;


void g(void)
{
	enum A { B = _Generic(&y, enum A*: 1, default: 7) };
	_Static_assert(7 == B, "");
}

