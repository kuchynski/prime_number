//
// kuchynskiandrei@gmail.com
// 2021
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MIN_VALUE 1234567890
#define MAX_VALUE 1234567999
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
			for (unsigned i = index + number; i < N_MAX_VALUE; i += number) {
				numbers[i] = 0;
			}
		}
	}

	// Print results
	unsigned total_number = (MIN_VALUE <= 2)? 1 : 0;

	for(unsigned i = N_MIN_VALUE; i < N_MAX_VALUE; i++) {
		if(numbers[i]) {
			total_number ++;
			printf("%d\n", get_number(i));
		}
	}
	printf("There are %d primes in the range %d - %d\n", total_number, MIN_VALUE, MAX_VALUE);

	free(numbers);
}
