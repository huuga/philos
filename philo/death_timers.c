#include "philo.h"

void	*first_death_timer(void *phil)
{
	int	curr_started_eating;

	curr_started_eating = ((t_phil *)phil)->started_eating;
	usleep(((t_phil *)phil)->ttd * 1000);
	if (curr_started_eating == ((t_phil *)phil)->started_eating)
		print_death(phil);
	return (NULL);
}

void	*death_timer(void *phil)
{
	int	curr_started_eating;

	curr_started_eating = ((t_phil *)phil)->started_eating;
	usleep(((t_phil *)phil)->ttd * 1000);
	if (curr_started_eating == ((t_phil *)phil)->started_eating)
		print_death(phil);
	return (NULL);
}
