//This changes all letters to lowercase and last letters of word to upper case.
//Run this like ./a.out "This is a test" --> thiS iS A tesT

#include <unistd.h>

#define TOLOWER(c) (c | ' ')
#define TOUPPER(c) (c & '_')

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_isspace(char str)
{
	if (str == ' ' || str == '\t')
		return (1);
	return (0);
}

void 	rstr_capitalizer(char *str)
{
	int i = 0;
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			ft_putchar(str[i++]);
		if (!(ft_isspace(str[i + 1])))
			ft_putchar(TOLOWER(str[i++]));
		while (str[i] && ((ft_isspace(str[i + 1]) || (str[i + 1] == '\0'))))
			ft_putchar(TOUPPER(str[i++]));
	}
}

int 	main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc > 1)
	{
		*argv++;
		while (*argv)
		{
			rstr_capitalizer(*argv++);
			write(1, "\n", 1);
		}
	}
	return (0);
}
