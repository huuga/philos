#include "philo.h"

static void	*left_hand(void *pointer)
{
	t_phil		*phil;
	pthread_t	print_tread;

	phil = (t_phil *)pointer;
	pthread_mutex_lock(&(phil->forks[phil->phil_nbr - 1]));
	phil->locked_forks++;
	pthread_create(&print_tread, NULL, print_taken_fork, pointer);
	return (NULL);
}

static void	*right_hand(void *pointer)
{
	t_phil		*phil;
	pthread_t	print_thread;

	phil = (t_phil *)pointer;
	if (phil->phil_nbr == phil->total_num_of_phil)
		pthread_mutex_lock(&(phil->forks[0]));
	else
		pthread_mutex_lock(&(phil->forks[phil->phil_nbr]));
	phil->locked_forks++;
	pthread_create(&print_thread, NULL, print_taken_fork, pointer);
	return (NULL);
}

void	forks_search_and_eating(t_phil *phil)
{
	pthread_t	left;
	pthread_t	right;
	pthread_t	death_timer_str;
	pthread_t	print_eat;

	pthread_create(&left, NULL, left_hand, (void *)phil);
	pthread_create(&right, NULL, right_hand, (void *)phil);
	while (phil->locked_forks != 2)
		;
	phil->locked_forks = 0;
	phil->started_eating++;
	pthread_create(&print_eat, NULL, print_eating, (void *)phil);
	pthread_create(&death_timer_str, NULL, death_timer, (void *)phil);
}

void	forks_release(t_phil *phil)
{
	pthread_mutex_unlock(&(phil->forks[phil->phil_nbr - 1]));
	if (phil->phil_nbr == phil->total_num_of_phil)
		pthread_mutex_unlock(&(phil->forks[0]));
	else
		pthread_mutex_unlock(&(phil->forks[phil->phil_nbr]));
}
