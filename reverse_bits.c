#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int i = 1;
	i = 256; //i <<= 8; //tai 256;
	while (i >>= 1)
		(octet & i) ? write(1, "1", 1) : write(1, "0", 1);
}

unsigned char reverse_bits(unsigned char b)
{
	unsigned char	r = 0;
	unsigned		char_len = 8;

	while (char_len--)
	{
		r = (r << 1) | (b & 1);
		b >>= 1;
	}
	return (r);
}

int main(void)
{
	int n = 64;
	print_bits(n);
	write(1, "\n", 1);
	print_bits(reverse_bits(n));
	write(1, "\n", 1);
	return (0);
}