#ifndef __BITMAP__H__
#define __BITMAP__H__


static inline void set_bit(unsigned bitmap[], unsigned n)
{
	unsigned word_size = sizeof(unsigned) * 8;
	unsigned i = n / word_size;
	unsigned j = n % word_size;

	bitmap[i] |= (1 << j);
	return;
}

static inline void reset_bit(unsigned bitmap[], unsigned n)
{
	unsigned word_size = sizeof(unsigned) * 8;
	unsigned i = n / word_size;
	unsigned j = n % word_size;

	bitmap[i] &= ~(1 << j);
	return;
}


static inline unsigned read_bit(unsigned bitmap[], unsigned n)
{
	unsigned word_size = sizeof(unsigned) * 8;
	unsigned i = n / word_size;
	unsigned j = n % word_size;
	
	return (bitmap[i] & (1 << j));
}
#endif

