#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int i = 1;
	if (ac == 1)
	{
		write (2, "NOT_ENOUGHT_PARAMETTRE!!", 24);
		return (0);
	}
	while (av[i])
	{
		printf(" %s", av[i]);
		i++;
	}
	int j = 0;
	while (j == 0)
	{
		printf("%s\n", av[i]);
		i++;
	}
	
	return 0;
}