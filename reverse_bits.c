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

unsigned char reverse_bits2(unsigned char b)
{
	b = (b & 0xF0) >> 4 | (b & 0x0F) << 4; // 1)
	b = (b & 0xCC) >> 2 | (b & 0x33) << 2; // 2)
	b = (b & 0xAA) >> 1 | (b & 0x55) << 1; // 3)
	return (b);
}

unsigned char reverse_bits3(unsigned char b)
{
	b = (b * 0x0202020202ULL & 0x010884422010ULL) % 0x3ff;
	return (b);
}

int main(void)
{
	int n = 64;
	print_bits(n);
	write(1, "\n", 1);
	print_bits(reverse_bits(n));
	write(1, "\n", 1);
	print_bits(reverse_bits2(n));
	write(1, "\n", 1);
	print_bits(reverse_bits3(n));
	write(1, "\n", 1);
	return (0);
}