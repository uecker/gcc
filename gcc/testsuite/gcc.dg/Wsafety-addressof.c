/* { dg-do compile } */
/* { dg-options "-Wsafety=1" } */

void f(int i)
{
	int z = 1;
	&z;
	&f;
	&i;
	int x;
	&x;	/* { dg-warning "Unsafe addressof" } */
}

