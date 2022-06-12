/*
 * { dg-do compile }
 * { dg-options "-ftag-compat" }
 */


enum aa { A = 1 } *a;
enum bb { B = 1 } *b;

void test(void)
{
  enum aa { A = 1 } *c = a;
  enum bb { B = 2 } *d = b;	/* { dg-warning "incompatible pointer type" } */
}

enum cc { C = 1 };
enum cc { D = 1 };		/* { dg-error "conflicting redefinition" } */	

enum dd { E = 1 };
enum dd { E = 2 };		/* { dg-error "conflicting redefinition" } */	
				/* { dg-error "redeclaration of enumerator" "" { target *-*-* } .-1 } */	



void test2(void)
{
  enum ee *a;
  enum ee { F = 2 } *b;
  b = a;
}


enum ff { G = 2 };
enum gg { G = 2 };		/* { dg-error "redeclaration of enumerator" } */
enum g2 { G = 3 };		/* { dg-error "redeclaration of enumerator" } */

enum hh { H = 1, H = 1 };	/* { dg-error "redeclaration of enumerator" } */

enum ss { K = 2 };
enum ss { K = 2 };

enum tt { R = 2 } TT;
enum tt {
	R = _Generic(&TT, enum tt*: 0, default: 2)
};




