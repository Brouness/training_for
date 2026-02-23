#include <unistd.h>

void	ft_putnbr(int s)
{
	char c;

	if (s >= 10)
	{
		ft_putnbr(s / 10);
		ft_putnbr(s % 10);
	}
	if (s < 10)
	{
		c = s + '0';
		write (1, &c, 1);
	}
}

int main()
{
	int i;
	i = 1;
	while (i <= 100)
	{
		
		if (i % 3 == 0 && i % 5 == 0)
			write (1, "fizzbuzz\n", 10);
		else if (i % 3 == 0)	
			write(1, "fizz\n", 5);
		else if (i % 5 == 0)
			write (1, "buzz\n", 5);
		else
		{
			ft_putnbr(i);
			write (1, "\n", 1);
		}
		i++;
	}
}