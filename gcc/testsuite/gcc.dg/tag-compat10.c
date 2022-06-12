/*
 * { dg-do compile }
 * { dg-options "-ftag-compat" }
 */


extern struct __attribute__(( aligned (16) )) foo { int x; } x;
extern struct bar { float x; } y;

void test(void)
{
  extern struct __attribute__(( aligned (8) )) foo { int x; } x;	/* { dg-error "conflicting types" } */
  extern struct bar { int x; } y;					/* { dg-error "conflicting types" } */
}

