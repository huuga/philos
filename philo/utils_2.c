#include "philo.h"

long	diff_time_calculate(struct timeval *curr_time,
			struct timeval *epoch_begin)
{
	long	res;

	res = (curr_time->tv_usec + (curr_time->tv_sec * 1000000))
		- ((epoch_begin->tv_sec * 1000000) + epoch_begin->tv_usec);
	return (res / 1000);
}

int	no_args(void)
{
	printf("Input 4 or 5 integer arguments\n");
	return (1);
}

int	numbers_of_philosophers(char *argv)
{
	long	res;

	res = ft_atoi(argv);
	if (res == -3000000000)
		return (-1);
	return ((int)res);
}
