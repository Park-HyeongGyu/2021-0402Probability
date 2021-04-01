#include <stdio.h>
#include <math.h>

void PrintCase(unsigned long long a);

int main()
{
	const long double numerator = 3996;
	const long double denominator = 456976; //26^4 == 456976
	const long double numerator_subed = denominator - numerator;

	long double p_made = numerator / denominator;
	long double p_not_made = numerator_subed / denominator;
	double p_value;
	unsigned long long count = 1;
	unsigned int diff = 100;

	printf("<p_made>\n");
	for(int a  = 1 ; a <= 6 ; a++)
	{
		printf("%d : %f\n", a, pow(p_made, (double)a));
	}
	printf("\n");

	p_value = pow(p_not_made, 1);
	while(p_value > 0.05)
	{
		//PrintCase(count);
		//printf("p_value : %f\n", p_value);
		count += 1;
		p_value = p_value * p_not_made;
	}
	PrintCase(count);
	printf("p_value : %f\n", p_value);

	// two words.
	const double not_two_words = 1 - pow(p_made, 2);
	count = 0;
	long double p_value_two = not_two_words;
	while(p_value_two > 0.05)
	{
		count += diff;
		p_value_two *= pow(not_two_words, (double)diff);
	}
	PrintCase(count);
	printf("p-value-two : %Lf\n", p_value_two);

	// three words.
	const double not_three_words = 1 - pow(p_made, 3);
	count = 0;
	long double p_value_three = not_three_words;
	while(p_value_three > 0.05)
	{
		count += diff;
		p_value_three *= pow(not_three_words, (double)diff);
	}
	PrintCase(count);
	printf("p-value-three : %Lf\n", p_value_three);

	// four words.
	const double not_four_words = 1 - pow(p_made, 4);
	count = 0;
	long double p_value_four = not_four_words;
	while(p_value_four > 0.05)
	{
		count += diff;
		p_value_four *= pow(not_four_words, (double)diff);
	}
	PrintCase(count);
	printf("p-value-four : %Lf\n", p_value_four);

	// five words.
	const double not_five_words = 1 - pow(p_made, 5);
	count = 0;
	long double p_value_five = not_five_words;
	while(p_value_five > 0.05)
	{
		count += diff;
		p_value_five *= pow(not_five_words, (double)diff);
	}
	PrintCase(count);
	printf("p-value-five : %Lf\n", p_value_five);

	// six words.
	const double not_six_words = 1 - pow(p_made, 6);
	diff = 10000;
	count = 0;
	long double p_value_six = not_six_words;
	while(p_value_six > 0.05)
	{
		count += diff;
		p_value_six *= pow(not_six_words, (double)diff);
	}
	PrintCase(count);
	printf("p-value-six : %Lf\n", p_value_six);

	return 0;
}

void PrintCase(unsigned long long a)
{
	unsigned long long b = a%10;
	switch(b)
	{
		case 0:
			printf("%lluth try\n", a);
			break;
		case 1:
			printf("%llust try\n", a);
			break;
		case 2:
			printf("%llund try\n", a);
			break;
		case 3:
			printf("%llurd try\n", a);
			break;
		case 4:
			printf("%lluth try\n",a);
			break;
		case 5:
			printf("%lluth try\n",a);
			break;
		case 6:
			printf("%lluth try\n",a);
			break;
		case 7:
			printf("%lluth try\n",a);
			break;
		case 8:
			printf("%lluth try\n",a);
			break;
		case 9:
			printf("%lluth try\n",a);
			break;
	}
}
