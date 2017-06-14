#include <stdio.h>
#include <stdlib.h>

#include "bitmap.h"

#define N 10000000


int main()
{
	unsigned word_size = sizeof(unsigned) * 8;
	unsigned bitmap_size = (N / word_size) + 1;
	unsigned number;
	unsigned bitmap[bitmap_size];

	for(unsigned i = 0 ; i < N; i++)
		reset_bit(bitmap, i);

	for(unsigned i = 0; i < N;)
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
