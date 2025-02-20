/* { dg-do compile } */
/* { dg-options "-Wsafety=1" } */

void f(int *p)
{
	p == p;
	p < p;		/* { dg-warning "Unsafe pointer arithmetic" } */
	p + 3;		/* { dg-warning "Unsafe pointer arithmetic" } */
	p++;		/* { dg-warning "Unsafe pointer arithmetic" } */
}

void g(int *p)
{
	*p;
	p[0];
#pragma GCC diagnostic warning "-Wsafety=2"
	*p;	/* { dg-warning "Unsafe pointer dereferenciation" } */
	p[0];	/* { dg-warning "Unsafe pointer dereferenciation" } */
}

