/*
 * { dg-do compile }
 * { dg-options "-ftag-compat" }
 */


typedef struct p { int a; } pd_t;
typedef struct p { int a; } pd_t;


void test1(void)
{
  pd_t y0;
  struct p { int a; } x;
  y0 = x;
}

void test2(void)
{
  struct p { int a; } x;
  struct p y0 = x;
}

void test3(void)
{
  struct p { int a; } x;
  pd_t y0 = x;
}

