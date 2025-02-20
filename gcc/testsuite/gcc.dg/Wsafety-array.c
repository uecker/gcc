/* { dg-do compile } */
/* { dg-options "-Wsafety=1" } */

void f(int *b)
{
	int a[1] = { 0 };       
	a[1];			/* { dg-warning "Unsafe array subscription" } */
	a[-1];			/* { dg-warning "Unsafe array subscription" } */
}


