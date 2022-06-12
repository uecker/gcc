/* PR c/89211 */
/* { dg-do compile } */
/* { dg-options "-fno-tag-compat" } */

void foo ();
void foo ()
{
  void foo (struct S);	/* { dg-warning "declared inside parameter list" } */
}
