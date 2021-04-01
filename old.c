#include <stdio.h>
#include <gmp.h>
#include <time.h>

int main()
{
	// about time
	time_t start, end;
	start = time(NULL);
	double result;

	// declaring variables.
	const unsigned long int GAP = 10000000;
	mpz_t son, mom, s_a, m_a; // s_a = son_accumulated, m_a = mom_accumulated
	mpz_t sGAP, mGAP;
	mpz_t monkey_count;
	mpq_t res, son_rat, mom_rat; // rat = rational number
	mpq_t s_level; // s_level = significance level
	const unsigned long int GAS = 1;

	//mpq_t cont_for_compare;

	// initializing variables.
	mpz_init(son);
	mpz_init(mom);
	mpz_init(s_a);
	mpz_init(m_a);
	mpz_init(monkey_count);
	mpz_init(sGAP);
	mpz_init(mGAP);

	mpq_init(res);
	mpq_init(son_rat);
	mpq_init(mom_rat);
	mpq_init(s_level);
	//mpq_init(cont_for_compare);
	printf("one");

	// allocate numbers.
	mpz_set_ui(monkey_count, 0);

	mpz_set_ui(mom, 27);
	mpz_pow_ui(mom, mom, 30);
	mpz_set(son, mom);
	mpz_sub_ui(son, son, 1);

	mpz_pow_ui(mGAP, mom, GAP);
	mpz_pow_ui(sGAP, son, GAP);

	mpz_set_ui(s_a, 1);
	mpz_set_ui(m_a, 1);
	
	mpq_set_z(res, s_a);
	mpq_set_ui(s_level, 1, 20);

	//mpq_set(cont_for_compare, res);

	printf("start!");
	// Arithmetic process.
	while(mpq_cmp(res, s_level) > 0)
	/* <Explanation about func mpq_cmp>
	 * If res > s_level, it returns positive,
	 * Else if res == s_level, it returns zero,
	 * Else if res < s_level, it returns negative.
	 * Return type is int.
	 * For more information, refer 55p of the official manual.
	 */
	{
		mpz_mul(s_a, sGAP, s_a);
		mpz_mul(m_a, mGAP, m_a);

		mpq_set_z(son_rat, s_a);
		mpq_set_z(mom_rat, m_a);

		mpq_div(res, son_rat, mom_rat);
		mpq_canonicalize(res);

		printf("hi");

		mpz_add_ui(monkey_count, monkey_count, GAS);
		gmp_printf("monkey : %zd\n", monkey_count);

		//if(mpq_cmp(cont_for_compare, res) <= 0)
		//{
	//		printf("error\n");
//			return 0;
//		}
		
		//mpq_set(cont_for_compare, res);
	}

	gmp_printf("this is money's number : %Zd\n", monkey_count);
	printf("this is GAP : %lu", GAP);


	// clear the memory locations for the variables.
	mpz_clear(son);				
	mpz_clear(mom);
	mpz_clear(s_a);
	mpz_clear(m_a);
	mpz_clear(monkey_count);
	mpz_clear(sGAP);
	mpz_clear(mGAP);

	mpq_clear(res);
	mpq_clear(son_rat);
	mpq_clear(mom_rat);
	mpq_clear(s_level);
	//mpq_clear(cont_for_compare);

	// checking time
	end = time(NULL);
	result = (double)(end - start);
	printf("time : %f", result);

	return 0;
}
