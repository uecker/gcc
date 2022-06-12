/*
 * { dg-do run }
 * { dg-options "-ftag-compat -O2" }
 */


typedef struct { int x; } foo_t;

int test_foo(foo_t* a, void* b)
{
	a->x = 1;

	struct { int x; }* p = b;
	p->x = 2;

	return a->x;
}


struct bar { int x; int f[]; };

int test_bar1(struct bar* a, void* b)
{
	a->x = 1;

	struct bar { int x; int f[]; }* p = b;
	p->x = 2;

	return a->x;
}

int test_bar2(struct bar* a, void* b)
{
	a->x = 1;

	struct bar { int x; int f[0]; }* p = b;
	p->x = 2;

	return a->x;
}

int test_bar3(struct bar* a, void* b)
{
	a->x = 1;

	struct bar { int x; int f[1]; }* p = b;
	p->x = 2;

	return a->x;
}



int main()
{
	foo_t y;

	// this works, but is not guaranteed by C
	if (2 == test_foo(&y, &y))
		__builtin_abort();

	struct bar z;

	if (2 != test_bar1(&z, &z))
		__builtin_abort();

	if (2 != test_bar2(&z, &z))
		__builtin_abort();

	if (2 == test_bar3(&z, &z))
		__builtin_abort();
	
	return 0;
}


