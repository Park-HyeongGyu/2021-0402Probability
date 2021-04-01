#include <stdio.h>
#include <gmp.h>
#include <time.h>

int main()
{
	// about time
	time_t start, end;
	double result;
	start = time(NULL);

	// allocate
	unsigned long int count = 1;
	const unsigned long int GAP = 100; //man
	mpf_t son, mom, ratio, ratio_a, ratio_GAP;
	mpf_init2(son, 512);
	mpf_init2(mom, 512);
	mpf_init2(ratio, 512);
	mpf_init2(ratio_a, 512);
	mpf_init2(ratio_GAP, 512);

	// set variables
	mpf_set_ui(mom, 27);
	mpf_pow_ui(mom, mom, 30);
	mpf_sub_ui(son, mom, 1);
	mpf_div(ratio, son, mom);

	mpf_pow_ui(ratio_GAP, ratio, GAP);
	mpf_set(ratio_a, ratio);

	while(mpf_cmp_d(ratio, 0.05) > 0)
	{
		mpf_mul(ratio, ratio, ratio_GAP);
		count += 1;

		if(mpf_cmp(ratio_a, ratio) > 0)
		{
			printf("fuck");
			return 0;
		}

		mpf_set(ratio_a, ratio);

		printf("%lu\n", count);
	}

	// free
	mpf_clear(son);						
	mpf_clear(mom);
	mpf_clear(ratio);
	mpf_clear(ratio_a);
	mpf_clear(ratio_GAP);

	//end
	end = time(NULL);
	result = (double)(end-start);
	printf("time : %f\n", result);
	return 0;
}
