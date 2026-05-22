/* { dg-do compile } */
/* { dg-require-effective-target tls } */
/* { dg-options "-O2 -fno-pie -fdump-ipa-whole-program" } */

/* tls_model("initial-exec") must not be upgraded to local-exec even when
   the symbol is hidden and -fno-pie is used.  PR c/125418.  */
__attribute__((visibility("hidden")))
__attribute__((tls_model("initial-exec")))
extern __thread int x;

void reference(void) { x++; }

/* { dg-final { scan-ipa-dump "Varpool flags: tls-initial-exec" "whole-program" } } */
