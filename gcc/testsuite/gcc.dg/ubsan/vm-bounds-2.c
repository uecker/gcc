/* { dg-do compile } */
/* { dg-options "-fsanitize=vla-bound" } */



const char* name = "hallo";


void f(void)
{
	int x = 1;
	int (*m)[x] = 0;
	m = ({ long* d2; (int (*)[d2[0]])(0); });
}

