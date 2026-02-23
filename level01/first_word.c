#include <unistd.h>
int main(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ac == 2)
	{
		while (av[1][j] == 9 || av[1][j] == 32 && av[1][j])
			j++;
		while (av[1][j] != 32 && av[1][j] != 9 && av[1][j])
		{
			i++;
			j++;
		}
		//if (i == 1)
		//	return (write (1, "\n", 1), 1);
		j = j - i;
		while (av[1][j] != 32 && av[1][j] != 9 && av[1][j])
		{
			write(1, &av[1][j], 1);
			j++;
		}
	}
	write (1, "\n", 1);
}