#include "philo.h"

int	odd_threads_start(t_main_str *main_st)
{
	int				i;
	pthread_t		thread;

	i = 1;
	while (i <= main_st->numbers_of_phil)
	{
		main_st->curr_phil = i;
		if (pthread_create(&thread, NULL, life_of_phil, (void *)main_st))
			return (1);
		pthread_detach(thread);
		usleep(20);
		i = i + 2;
	}
	return (0);
}

int	even_threads_start(t_main_str *main_st)
{
	int			i;
	pthread_t	thread;

	i = 2;
	while (i <= main_st->numbers_of_phil)
	{
		main_st->curr_phil = i;
		if (pthread_create(&thread, NULL, life_of_phil, (void *)main_st))
			return (1);
		pthread_detach(thread);
		usleep(20);
		i = i + 2;
	}
	return (0);
}
