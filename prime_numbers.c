/* This program is licensed under the GNU GPLv3 or later */
/* gcc factorial.c -o Factorial -lgmp */

#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
  mpz_t prime_number;

  mpz_init_set_ui(prime_number,2); /* initialize prime_number and set it to 2 */
    
  for (long int i = 2; i <1002; i++)
  {
	mpz_nextprime (prime_number , prime_number);

	printf("%li nth prime = ", i-1);
    mpz_out_str(stdout,10,prime_number); /* output prime_number factor in base 10 */
    if (mpz_probab_prime_p(prime_number , 40) == 2) printf(" - Authentic prime!"); /* check if it is definately a prime or if it is a probabilistic prime */
    printf("\n");

  }
  
  mpz_clear(prime_number);  

  return 0;
}


