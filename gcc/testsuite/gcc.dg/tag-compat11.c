/*
 * { dg-do compile }
 * { dg-options "-ftag-compat" }
 */


extern struct { int x; } a;
extern struct { int x; } a;	/* { dg-error "conflicting types" } */


typedef struct { int x; } u;
typedef struct { int x; } v;

u b;
v b;				/* { dg-error "conflicting types" } */


