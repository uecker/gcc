/* { dg-do compile } */
/* { dg-options "-Wsafety=1" } */

typedef typeof(sizeof(0)) size_t;

void *mlloc0(size_t x);

void f(void)
{
	int *p = mlloc0(sizeof *p);	/* { dg-warning "Unsafe implicit conversion" } */
}

void g(void)
{
	int *p = mlloc0(1);	/* { dg-warning "Unsafe implicit conversion" } */
	int *q = 0;		/* { dg-warning "zero as" } */
	void *n = 0;		/* { dg-warning "zero as" } */
	int *z = n;		/* { dg-warning "Unsafe implicit conversion" } */
}

void h(void)
{
	int *p = __builtin_malloc(sizeof *p);
}

void i(void)
{
	int *p = __builtin_malloc(1);	/* { dg-warning "insufficient size" } */
}

