#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char * argv[])
{
    mpz_t c, p;
    unsigned long int odd_or_even; /* odd_or_even is a flag */

    mpz_init_set_ui(c,1234567891234567891); /*  This is the starting number  */
    mpz_init_set_ui(p,1); /* initialize p */

    mpz_out_str(stdout,10,c); /* output n in base 10 */
    printf("\n");

    while ( mpz_cmp_ui(c,1) != 0)
    {
    mpz_mod_ui(p,c,2); /* p = mod(c,2) */
    odd_or_even = mpz_get_ui( p ); /* odd_or_even is integer version of mpz_t p */

        if (odd_or_even == 1) /*if c is odd */
        {
            mpz_mul_ui(c,c,3); /* c = 3c */
            mpz_add_ui(c,c,1);  /* c = c+1 */
        }
        else /* if c is even */
        {
            mpz_cdiv_q_ui(c,c,2); /* c = c/2 */
        }

    mpz_out_str(stdout,10,c); /* output c in base 10 */
    printf("\n");
    }

    mpz_clear(c);
    mpz_clear(p);
    return 0;
}