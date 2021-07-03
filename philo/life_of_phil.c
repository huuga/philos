#include "philo.h"

static void	life_cycle(t_phil *phil)
{
	pthread_t	sleep_print;
	pthread_t	think_print;

	if (phil->is_alive)
		forks_search_and_eating(phil);
	usleep(phil->tte * 1000);
	forks_release(phil);
	pthread_create(&sleep_print, NULL, print_sleeping, (void *)phil);
	usleep(phil->tts * 1000);
	pthread_create(&think_print, NULL, print_thinking, (void *)phil);
}

static void	life_of_phil_2(t_phil *phil)
{
	pthread_t		first_death_thr;

	pthread_create(&first_death_thr, NULL, first_death_timer, (void *)phil);
	while (phil->times_of_meal > 0)
	{
		life_cycle(phil);
		phil->times_of_meal--;
	}
	if (phil->total_num_of_phil == phil->phil_nbr)
	{
		pthread_mutex_lock(phil->print_mutex);
		phil->is_alive = 0;
	}
}

void	*life_of_phil(void *pointer)
{
	t_phil			*phil;
	t_main_str		*main_st;
	int				i;
	pthread_t		first_death_thr;

	main_st = (t_main_str *)pointer;
	phil = main_st->list_of_phil;
	i = 0;
	while (i++ < main_st->curr_phil - 1)
		phil = phil->next;
	if (phil->phil_nbr == phil->total_num_of_phil)
		phil->next = main_st->list_of_phil;
	if (phil->times_of_meal != -1)
		life_of_phil_2(phil);
	else
	{
		pthread_create(&first_death_thr, NULL, first_death_timer, (void *)phil);
		while (1)
			life_cycle(phil);
	}
	return (NULL);
}
