/* PR sanitizer/80460 */
/* { dg-do compile } */
/* { dg-options "-fno-tag-compat" } */

int
f (int a, struct { int b[a]; } c) /* { dg-warning "anonymous struct declared inside parameter list will not be visible outside of this definition or declaration" } */
{
  return c.b[0];
}
