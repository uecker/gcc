/* { dg-do compile } */
/* { dg-options "-Wsafety=1" } */

void f()
{
	int i = 0;
	void *p = nullptr;

	// allowed casts
	(void)i;
	(long)p;
	(void*)p;
	(char*)p;
	(signed char*)p;
	(unsigned char*)p;

	// forbidden casts
	(char)i;		/* { dg-warning "Unsafe cast" } */
	(int*)p;		/* { dg-warning "Unsafe cast" } */
	(float*)p;		/* { dg-warning "Unsafe cast" } */
	(void*)0;
#pragma GCC diagnostic warning "-Wsafety=2"
	(void*)0;		/* { dg-warning "Unsafe cast" } */
}

