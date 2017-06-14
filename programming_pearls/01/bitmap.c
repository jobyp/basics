#include <stdio.h>
#include <stdlib.h>

#include "bitmap.h"

#define N 10000000

int main()
{
	unsigned word_size = sizeof(unsigned) * 8;
	unsigned bitmap_size = (N / word_size) + 1;
	unsigned bitmap[bitmap_size];
	unsigned number;

	/* printf("sizeof(bitmap) = %lu\n", sizeof(bitmap)); */
	
	for(unsigned i = 0 ; i < N; i++)
		reset_bit(bitmap, i);

	while(scanf(" %u", &number) != EOF)
		set_bit(bitmap, number);

	for(unsigned i = 0; i < N; i++)
	{
		if (read_bit(bitmap, i))
			printf("%u\n", i);
	}

	return 0;
}
