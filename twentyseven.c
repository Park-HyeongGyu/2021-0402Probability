#include <gmp.h>
#include <stdio.h>

int main()
{
	mpz_t a;
	mpz_init(a);

	mpz_set_ui(a, 27);
	mpz_pow_ui(a, a, 30);
	gmp_printf("%Zd\n", a);

	mpz_clear(a);

	return 0;
}
