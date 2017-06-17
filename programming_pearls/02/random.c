#include <stdio.h>
#include <stdlib.h>

#define N 4000000000

int main()
{
	for(unsigned i = 0; i < N; i++)
		printf("%u\n", (unsigned)rand());

	return 0;
}
