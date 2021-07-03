#include "philo.h"

pthread_t	*arr_init(int num_of_tr)
{
	pthread_t	*res;

	res = (pthread_t *)malloc(sizeof(pthread_t) * num_of_tr);
	if (res == NULL)
	{
		printf("arr_init error\n");
		return (NULL);
	}
	return (res);
}

pthread_mutex_t	*forks_arr_init(int	numbers_of_phil)
{
	int				i;
	pthread_mutex_t	*res;

	res = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * numbers_of_phil);
	if (res == NULL)
	{
		printf("arr_init error\n");
		return (NULL);
	}
	i = 0;
	while (i < numbers_of_phil)
	{
		pthread_mutex_init(&res[i], NULL);
		i++;
	}
	return (res);
}

int	main_st_init(t_main_str *main_st, char **argv)
{
	long	atoi_res;

	gettimeofday(&main_st->epoch_begin, NULL);
	if (pthread_mutex_init(&main_st->print_mutex, NULL))
		return (1);
	atoi_res = numbers_of_philosophers(argv[1]);
	if (atoi_res == -3000000000)
		return (1);
	main_st->numbers_of_phil = atoi_res;
	main_st->forks = forks_arr_init(main_st->numbers_of_phil);
	if (main_st->forks == NULL)
		return (1);
	main_st->list_of_phil = NULL;
	return (0);
}
