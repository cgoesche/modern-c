#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	double A[5] = {
		9.0,
		2.9,
		3.E+25,
		.00007,
	};
	
	for (i = 0; i < 5; ++i){
		printf("Item %d: \t%.2f\n", i, A[i]);
	}
	
	return EXIT_SUCCESS;
}

