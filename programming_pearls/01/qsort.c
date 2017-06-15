#include <stdio.h>
#include <stdlib.h>

#define N 10000000
#define NUMBER_OF_RANDOM_NUMBERS (N / 10)

static int compare(const unsigned *a, const unsigned *b)
{
        if ( *a < *b )
                return -1;
        else if ( *a > *b )
                return 1;
        else
                return 0;
}


int main()
{
        unsigned list[NUMBER_OF_RANDOM_NUMBERS] = {10, 12, 9, 4, 5};
        size_t count = 5;

        for(count = 0; count < NUMBER_OF_RANDOM_NUMBERS; count++)
        {
                if (scanf(" %d", &list[count]) == EOF)
                        break;
        }

        qsort( list,
               count,
               sizeof(unsigned),
               ( int (*)( const void*, const void * ) ) compare );

        for(size_t i = 0; i < count; i++)
                printf("%u\n", list[i]);

        return 0;
}
