#include <stdio.h>
#include <gmp.h>

int main()
{
	const unsigned long int SEVEN = 70000000;
	double result = 0;

	mpz_t numerator, denominator;
	mpq_t for_output;
	mpf_t num_f, den_f, res_f;

	mpz_init(numerator);
	mpz_init(denominator);
	mpq_init(for_output);
	mpf_init2(num_f, 256);
	mpf_init2(den_f, 256);
	mpf_init2(res_f, 256);

	mpz_set_ui(numerator, 27);
	mpz_pow_ui(numerator, numerator, 30);
	mpz_sub_ui(denominator, numerator, 1);

	printf("zero\n");

	mpz_pow_ui(numerator, numerator, SEVEN);
	mpz_pow_ui(denominator, denominator, SEVEN);

	gmp_printf("<numerator>\n%Zd\n\n", numerator);
	gmp_printf("<denominator>\n%Zd\n\n", denominator);

	mpz_clear(numerator);
	mpz_clear(denominator);
	mpq_clear(for_output);
	mpf_clear(num_f);
	mpf_clear(den_f);
	mpf_clear(res_f);
	return 0;
}
