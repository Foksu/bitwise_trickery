#include <stdio.h>
#include <stdlib.h>

int		is_power_of_2(unsigned int n)
{
    return (n > 0 && !(n & (n - 1)));
}

int	main(int ac, char **av)
{
	if (ac == 2)
    {
        printf("is %s power of 2? ", av[1]);
        is_power_of_2(atoi(av[1])) ? printf("Yes.\n") : printf("No.\n");
    }
    return (0);
}