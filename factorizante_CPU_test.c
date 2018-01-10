/* (c) 2017 - Nuno Ferreira
 * This program is licensed under the GNU GPLv3 or later */
/* gcc factorizante_v0.30.c -o Factorizante -lgmp */

#include <gmp.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char * argv[])
{
  clock_t begin = clock();	/*Start timer */
  mpz_t prime_number, number_to_factorize;
  int is_divisible;
  mpz_init_set_ui(prime_number,1); /* initialize prime_number */
  mpz_init_set_str (number_to_factorize, "321123456789201232424501203415", 10); /* inset here the number you want to factorize */

  while (1 > 0)
  {
    mpz_nextprime (prime_number , prime_number); /* find next prime number */
	
    while (mpz_divisible_p(number_to_factorize,prime_number) != 0) /* returns non-zero if number_to_factorize is divisible by prime_number */
    {
	  mpz_out_str(stdout,10,prime_number); /* output prime_number factor in base 10 */

    if (mpz_probab_prime_p(prime_number , 40) == 2)
    { 
      printf(" - Authentic prime!"); /* check if it is definately a prime or if it is a probabilistic prime */
      printf("\n");
    }
    
    mpz_cdiv_q(number_to_factorize,number_to_factorize,prime_number);  /* number_to_factorize = number_to_factorize / prime_number */ 
	  
    if (mpz_probab_prime_p(number_to_factorize , 40) != 0)  /* check if number_to_factorize is a prime */
	  {
	    mpz_out_str(stdout,10,number_to_factorize); /* output number_to_factorize factor in base 10 */
      printf("\n");

	    clock_t end = clock();
	    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
      printf("Tempo = %f seconds \n", time_spent); /* show elapsed time */
	  printf("Fim! \n");
				
      mpz_clear(prime_number);  
      mpz_clear(number_to_factorize);
      return 0;
      }
    }
  }
  
  mpz_clear(prime_number);  
  mpz_clear(number_to_factorize);

  return 0;
}


