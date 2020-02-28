//This changes all letters to lowercase and first letters of words to upper case.
//Run this like ./a.out "This is a test" --> This Is A Test

#include <unistd.h>

#define TOLOWER(c) (c | ' ')
#define TOUPPER(c) (c & '_')

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int		ft_tolower(char c)
{
	return (c | ' ');
}

int		ft_toupper(char c)
{
	return (c & '_');
}

void	str_capitaliser(char *s)
{
	while (*s)
	{
		while (ft_isspace(*s))
			ft_putchar(*s++);
		if (*s && !ft_isspace(*s))
			ft_putchar(TOUPPER(*s++)); //(ft_toupper(*s++));
		while (*s && !ft_isspace(*s))
			ft_putchar(TOLOWER(*s++));//(ft_tolower(*s++));
	}
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		++av;
		while (*av)
		{
			str_capitaliser(*av++);
			write(1, "\n", 1);
		}
	}
	return (0);
}
