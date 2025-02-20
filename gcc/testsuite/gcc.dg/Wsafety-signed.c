/* { dg-do compile } */
/* { dg-options "-Wsafety=1" } */

int foo(int a, int b)
{
	return a * b;
}

unsigned short bar(unsigned short a, unsigned short b)
{
	return a * b;
}

unsigned int baz(unsigned int a, unsigned int b)
{
	return a * b;
}

#pragma GCC diagnostic warning "-Wsafety=2"

int foo1(int a, int b)
{
	return a * b;	/* { dg-warning "Unsafe signed integer" } */
}

unsigned short bar1(unsigned short a, unsigned short b)
{
	return a * b;	/* { dg-warning "Unsafe signed integer" } */
}

unsigned int baz1(unsigned int a, unsigned int b)
{
	return a * b;
}

