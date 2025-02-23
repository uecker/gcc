/* { dg-do compile } */
/* { dg-options "-Wsafety=1" } */

union { int x; float a; } z;	/* { dg-warning "Unsafe use of union" } */
void g(char * restrict p); 	/* { dg-warning "Unsafe use" } */

// allowed in dynamic mode
//
_Noreturn void f();

void t(int n)
{
	char buf[n];
}

void u(void (*fu)())
{
	fu();
}

#pragma GCC diagnostic warning "-Wsafety=2"

_Noreturn void h();		/* { dg-warning "Unsafe use" } */

void s(int n)
{
	char buf[n];		/* { dg-warning "Unsafe use" } */
}

void v(void (*fu)())
{
	fu();			/* { dg-warning "Unsafe function call" } */
}

