#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bitmap.h"

#define N 4000000000

/* We can only use 1 MiB of RAM */
#define ARRAY_SIZE (1024 * 1024 * 8 / 32)
#define STEP (1024 * 1024 * 8)

int main(int argc, char *argv[])
{
	unsigned bitmap[ARRAY_SIZE];
	FILE *num_list;

	if (argc != 2)
	{
		fprintf(stderr, "usage: %s <name of the file containing 4000000000 random numbers>\n", argv[0]);
		exit(1);
	}

	if ((num_list = fopen(argv[1], "r")) == NULL)
	{
		perror("fopen()");
		exit(1);
	}
	
	for(unsigned i = 0; i < N; i++)
	{
		unsigned lower_bound = i;
		unsigned upper_bound = ((i + STEP) < N) ? (i + STEP) : N;
		unsigned number;
		
		/* Initialize bitmap to 0 */
		memset(bitmap, 0, ARRAY_SIZE);
		rewind(num_list);
		
		for(unsigned j = lower_bound; j < upper_bound;)
		{
			if (fscanf(num_list, " %u", &number) != EOF)
			{
				if (lower_bound <= number && number < upper_bound)
				{
					set_bit(bitmap, (number - lower_bound));
					j++;
				}
			}
			else
				break;
		}

		/* Have we found a missing number? */
		for (unsigned j = 0; j < STEP; j++)
		{
			if (read_bit(bitmap, j) == 0)
			{
				printf("%u\n", (j + lower_bound));
				goto end;
			}
		}
		
		i = upper_bound;
	}

end:
	exit(0);
}
