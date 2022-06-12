/*
 * { dg-do compile }
 * { dg-options "-ftag-compat" }
 */




struct foo {
	char x[10];
} x;

struct foo {
	char x[_Generic(&x, struct foo*: 1, default: 10)];
};

void f(void)
{
	struct foo { char x[_Generic(&x, struct foo*: 1, default: 10)]; };

	struct foo z;
	_Static_assert(10 == sizeof(z.x), "");
}

enum A { B = 7 } y;
enum A { B = 7 };

enum A { B = _Generic(&y, enum A*: 1, default: 7) };

void g(void)
{
	enum A { B = _Generic(&y, enum A*: 1, default: 7) };
	_Static_assert(7 == B, "");
}

enum X { E = 1, F = 1 + 1 };
enum X { F = 2, E = 1 };



