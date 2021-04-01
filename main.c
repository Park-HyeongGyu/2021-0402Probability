#include <stdio.h>
#include <gmp.h>
#include <time.h>

// numerator : son
// denominator : mom

int is_finished(mpz_t numerator, mpz_t denominator);

int main()
{
	// about time.
	time_t start, end;
	start = time(NULL);
	double result;

	// declaring variables.
	const unsigned int ORIGINAL_EXPONENT = 10000000;
	unsigned int monkey_numbers = 0;
	mpz_t son_ori, mom_ori;
	mpz_t son, mom;

	// initializing
	mpz_init(son);
	mpz_init(mom);
	mpz_init(son_ori);
	mpz_init(mom_ori);

	// Assignment
	mpz_set_ui(mom_ori, 27);
	mpz_pow_ui(mom_ori, mom_ori, 30);
	mpz_sub_ui(son_ori, mom_ori, 1);

	mpz_set_ui(mom, 1);
	mpz_set_ui(son, 1);

	mpz_pow_ui(mom_ori, mom_ori, ORIGINAL_EXPONENT);
	mpz_pow_ui(son_ori, son_ori, ORIGINAL_EXPONENT);

	while(!is_finished(son, mom))
	{
		monkey_numbers += 1;
		mpz_mul(son, son, son_ori);
		mpz_mul(mom, mom, mom_ori);

		printf("this is monkey : %u\n", monkey_numbers);
	}

	// deallocate memory
	mpz_clear(son);
	mpz_clear(mom);
	mpz_clear(son_ori);
	mpz_clear(mom_ori);
	
	// end of the program
	end = time(NULL);
	result = (double)(end - start);
	printf("time : %f", result);
	return 0;
}

/*
int main()
{
	mpz_t one, two;
	mpz_init(one);
	mpz_init(two);

	mpz_set_ui(one, 1);
	mpz_set_ui(two, 8);
	printf("%d\n", is_finished(one, two));

	return 0;
}
*/

int is_finished(mpz_t numerator, mpz_t denominator)
// Very bad function name. As I think.
{
	mpz_t numerator_fourth;
	int to_return; // if positive, 4*numerator <= denominator

	mpz_init(numerator_fourth);

	mpz_mul_ui(numerator_fourth, numerator, 4);

	if(mpz_cmp(numerator_fourth, denominator) <= 0)
	{
		to_return = 1;
	}
	else
	{
		to_return = 0;
	}

	mpz_clear(numerator_fourth);

	return to_return;
}

