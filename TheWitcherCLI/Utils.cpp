#include "stdafx.h"
#include "Utils.h"

int generate_hit(int max_hit)
{
	//srand((unsigned)time(NULL));
	double x1 = rand();
	double x2 = RAND_MAX;

	return (int)(max_hit*(x1/x2));
}

int generate_random_item_level()
{
	//srand((unsigned)time(NULL));
	return rand() % 30 + 1;
}

int generate_random_price(int max)
{
	//srand((unsigned)time(NULL));
	double x1 = rand();
	double x2 = RAND_MAX;
	return (int)(max * (x1/x2));
}

int generate_random_index(int max)
{
	//srand((unsigned)time(NULL));
	double x1 = rand();
	double x2 = RAND_MAX;
	return (int) (max * x1/x2);
}
