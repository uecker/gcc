/*
 * { dg-do run }
 * { dg-options "-ftag-compat -flto -O2" }
 */


struct foo { int x; };

int test_foo1(struct foo* a, void* b)
{
	a->x = 1;

	struct foo { int x; int y; }* p = b;
	p->x = 2;

	return a->x;
}

int test_foo2(struct foo* a, void* b)
{
	a->x = 1;

	struct fox { int x; }* p = b;
	p->x = 2;

	return a->x;
}

enum bar { A = 1, B = 3, C = 5, D = 9 };

int test_bar1(enum bar* a, void* b)
{
	*a = A;

	enum bar { A = 1, B = 3, C = 6, D = 9 }* p = b;
	*p = B;

	return *a;
}

int test_bar2(enum bar* a, void* b)
{
	*a = A;

	enum baX { A = 1, B = 3, C = 5, D = 9 }* p = b;
	*p = B;

	return *a;
}


int main()
{
	struct foo y;

	if (1 != test_foo1(&y, &y))
		__builtin_abort();

	if (1 != test_foo2(&y, &y))
		__builtin_abort();

	enum bar z;

	if (A == test_bar1(&z, &z))
		__builtin_abort();

	if (A == test_bar2(&z, &z))
		__builtin_abort();

	return 0;
}


