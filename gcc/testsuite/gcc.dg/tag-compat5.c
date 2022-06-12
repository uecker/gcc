/*
 * { dg-do compile }
 * { dg-options "-ftag-compat" }
 */


extern struct foo { int x; } x;
extern struct bar { float x; } y;

void test(void)
{
  extern struct foo { int x; } x;
  extern struct bar { int x; } y;	/* { dg-error "conflicting types" } */
}

