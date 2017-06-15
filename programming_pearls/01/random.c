#define _SVID_SOURCE 1
#include <stdio.h>
#include <stdlib.h>

#include "bitmap.h"

#define N 10000000
#define NUMBER_OF_RANDOM_NUMBERS (N / 10)

int main()
{
	unsigned word_size = sizeof(unsigned) * 8;
	unsigned bitmap_size = (N / word_size) + 1;
	unsigned number;
	unsigned bitmap[bitmap_size];

	for(unsigned i = 0 ; i < N; i++)
		reset_bit(bitmap, i);

	for(unsigned i = 0; i < NUMBER_OF_RANDOM_NUMBERS;)
	{
		number = random();
		/* printf("---> %u\n", number); */

		/* Skip random numbers >= 10_000_000 */
		if ( number >= N )
			continue;

		if ( read_bit(bitmap, number))
			continue; /* Seen this before -- duplicates are not allowed */
		else
			printf("%u\n", number);

		set_bit(bitmap, number);
		i++;
	}

	return 0;
}
