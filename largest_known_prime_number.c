/* This program is licensed under the GNU GPLv2 or later */

/* The largest known marsenne prime is 2^74,207,281−1 as of October 2017 */
#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char * argv[])
{
  mpz_t a;
  int base, exponent;
  mpz_init(a);

  base = 2;
  exponent = 74207281;

  mpz_ui_pow_ui (a, base, exponent); /* a = base ^ exponent */
  mpz_sub_ui(a,a,1);  /* a = a - 1 */

  mpz_out_str(stdout,10,a); /* output c in base 10 */

  mpz_clear(a);

  return 0;
}
