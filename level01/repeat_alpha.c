#include <unistd.h>

int main(int ac, char **av)
{
	int i = 0;
	while (av[1][i])
	{
		int size = av[1][i] - 96;
		while (size > 0)
		{
			write(1, &av[1][i], 1);
			size--;
		}
		i++;
	}
}