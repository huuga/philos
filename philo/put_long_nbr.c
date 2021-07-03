#include "philo.h"

static void	negative(long n, int fd)
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

static void	positive(long n, int fd)
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

void	ft_put_long_nbr_fd(long n, int fd)
{
	if (n >= 0)
		positive(n, fd);
	else
		negative(n, fd);
}
