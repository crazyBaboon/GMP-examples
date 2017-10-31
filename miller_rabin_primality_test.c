/* This program is licensed under the GNU GPLv2 or later */

#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char * argv[])
{
    mpz_t a;

    int is_it_prime;

    mpz_init_set_ui(a,3); /*  a = 3  */

    is_it_prime = mpz_probab_prime_p (a, 20); /* this function tests if a is a prime number. It returns 2 if yes, 1 if maybe, 0 if a is not a prime. */

    mpz_out_str(stdout,10,a); /* output c in base 10 */

    switch ( is_it_prime ) {
      case 0: printf(" is not a prime number \n"); break;
      case 1: printf(" is probably a prime number\n"); break;
      case 2: printf(" is definately a prime number\n"); break;
    }

    mpz_clear(a);

    return 0;
}
