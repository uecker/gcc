/* { dg-do compile } */
/* { dg-options "-Wsafety=1" } */

void f(int *p)
{
	p == p;
	p < p;		/* { dg-warning "Unsafe pointer arithmetic" } */
	p + 3;		/* { dg-warning "Unsafe pointer arithmetic" } */
	p++;		/* { dg-warning "Unsafe pointer arithmetic" } */
}


