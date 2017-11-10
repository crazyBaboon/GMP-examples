/* This program is licensed under the GNU GPLv2 or later */
/* gcc factorial.c -o Factorial -lgmp */

#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char * argv[])
{
    mpz_t factorial_n;
    unsigned long int n = 120;
    mpz_init(factorial_n);
    
    mpz_fac_ui(factorial_n, n); /* factorial_n = n! */

    printf("Factorial of %i = ",n);
    mpz_out_str(stdout,10,factorial_n); /* output factorial_n in base 10 */
    printf("\n");

    mpz_clear(factorial_n);

    return 0;
}
