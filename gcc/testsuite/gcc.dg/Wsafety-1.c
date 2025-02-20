/* { dg-do compile } */
/* { dg-options "-Wsafety=1" } */

void a()
{
	goto a;			/* { dg-warning "jump skips" } */
	int i = 1;
a:
}

void b()
{
	extern int i;		/* { dg-warning "nested extern" } */
}

void c()
{
	const int *c;
	(int*)c;		/* { dg-warning "cast discards" } */
}

int d()
{
}				/* { dg-warning "return" } */

int e()
{
	return;			/* { dg-error "return" } */
}


