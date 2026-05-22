/* { dg-do compile } */
/* { dg-require-effective-target tls } */
/* { dg-options "-O2 -fno-pie -fdump-ipa-whole-program" } */

/* Hidden extern TLS variable made weak via #pragma weak must not be upgraded
   to local-exec: undefined weak symbols don't bind locally.  PR c/107419.  */
__attribute__((visibility("hidden")))
extern __thread int t;

#pragma weak t

int *f(void) { return &t; }

/* { dg-final { scan-ipa-dump "Varpool flags: tls-initial-exec" "whole-program" } } */
