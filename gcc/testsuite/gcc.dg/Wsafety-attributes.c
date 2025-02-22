/* { dg-do compile } */
/* { dg-options "-Wsafety=1" } */

[[noreturn]] void g(void);	/* { dg-warning "Unsafe use of attribute" } */

void f(int n, int buf[n]);
void h(int n, int *buf) [[gnu::access(read_write, 2, 1)]];


