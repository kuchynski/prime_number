//
// kuchynskiandrei@gmail.com
// 2021
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MIN_VALUE 0
#define MAX_VALUE 100000
#define N_MAX_VALUE (MAX_VALUE / 2 - 1)
#define N_MIN_VALUE (MIN_VALUE / 2)

unsigned get_number(unsigned n)
{
	return n + n + 3;
}

void main(void)
{
	// Init
	unsigned char *numbers = malloc(N_MAX_VALUE);
	const unsigned end = sqrt(N_MAX_VALUE / 2);
	memset(numbers, 0xFF, N_MAX_VALUE);

	// Calculate
	for(unsigned index = 0; index < end; index++) {
		if(numbers[index]) {
			const unsigned number = get_number(index);
			unsigned i = index + number;
			while(i < N_MAX_VALUE) {
				numbers[i] = 0;
				i += number;
			}
		}
	}

	// Print results
	unsigned total_number = 0;
	if(MIN_VALUE < 3) {
		total_number = 1;
		//printf("1 - 2\n");
	}

	for(unsigned i = N_MIN_VALUE; i < N_MAX_VALUE; i++) {
		if(numbers[i]) {
			total_number ++;
			//printf("%d - %d\n", total_number, get_number(i));
		}
	}
	printf("There are %d primes in the range %d - %d\n", total_number, MIN_VALUE, MAX_VALUE);

	free(numbers);
}
