#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int main(int argc, char * argv[]){

    mpz_t a, b, c;

    mpz_init_set_ui(a,1); /*  a = 1  */
    mpz_init_set_ui(b,1); /*  b = 1  */
    mpz_init(c);

    for (int i=1; i <= 2 ; ++i){
        mpz_add(c,a,b); /* c = a + b */
        mpz_mul_ui(a,b,1);
        mpz_mul_ui(b,c,1);
    }

    mpz_out_str(stdout,10,c);
    printf ("\n");
    mpz_clear(a);
    mpz_clear(b);
    mpz_clear(c);

    return 1;
}
