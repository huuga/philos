#include "philo.h"

static void	negative(int n, int fd)
{	
	char	c;

	if (n > (-10))
	{
		write(fd, "-", 1);
		c = (-n) + 48;
		write(fd, &c, 1);
		return ;
	}
	negative(n / 10, fd);
	c = -(n % 10) + 48;
	write(fd, &c, 1);
}

static void	positive(int n, int fd)
{	
	char	c;

	if (n < 10)
	{
		c = n + 48;
		write(fd, &c, 1);
		return ;
	}
	positive(n / 10, fd);
	c = (n % 10) + 48;
	write(fd, &c, 1);
}

void	ft_put_int_nbr_fd(int n, int fd)
{
	if (n >= 0)
		positive(n, fd);
	else
		negative(n, fd);
}
