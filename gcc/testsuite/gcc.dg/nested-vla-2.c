/* { dg-do run } */
/* { dg-options "-std=gnu99" } */


int main()
{
	int n = 1;

	typeof(char (*)[++n]) bar(void) { }

	if (2 != n)
		__builtin_abort();

	if (2 != sizeof(*bar()))
		__builtin_abort();

	if (2 != n)
		__builtin_abort();

	n = 1;

	typeof(char (*)[++n]) (*bar2)(void) = bar;

	if (2 != n)
		__builtin_abort();

	if (2 != sizeof(*(*bar2)()))
		__builtin_abort();

	if (2 != n)
		__builtin_abort();
}

