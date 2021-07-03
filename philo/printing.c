#include "philo.h"

void	*print_sleeping(void *pointer)
{
	struct timeval	curr_time;
	long			diff_time;
	t_phil			*phil;

	gettimeofday(&curr_time, NULL);
	phil = (t_phil *)pointer;
	diff_time = diff_time_calculate(&curr_time, phil->epoch_begin);
	pthread_mutex_lock(phil->print_mutex);
	ft_put_long_nbr_fd(diff_time, 1);
	write(1, " ", 1);
	ft_put_int_nbr_fd(phil->phil_nbr, 1);
	write(1, " is sleeping\n", 13);
	pthread_mutex_unlock(phil->print_mutex);
	return (NULL);
}

void	*print_eating(void *pointer)
{
	struct timeval	curr_time;
	long			diff_time;
	t_phil			*phil;

	gettimeofday(&curr_time, NULL);
	phil = (t_phil *)pointer;
	diff_time = diff_time_calculate(&curr_time, phil->epoch_begin);
	pthread_mutex_lock(phil->print_mutex);
	ft_put_long_nbr_fd(diff_time, 1);
	write(1, " ", 1);
	ft_put_int_nbr_fd(phil->phil_nbr, 1);
	write(1, " is eating\n", 11);
	pthread_mutex_unlock(phil->print_mutex);
	return (NULL);
}

void	*print_thinking(void *pointer)
{
	struct timeval	curr_time;
	long			diff_time;
	t_phil			*phil;

	gettimeofday(&curr_time, NULL);
	phil = (t_phil *)pointer;
	diff_time = diff_time_calculate(&curr_time, phil->epoch_begin);
	pthread_mutex_lock(phil->print_mutex);
	ft_put_long_nbr_fd(diff_time, 1);
	write(1, " ", 1);
	ft_put_int_nbr_fd(phil->phil_nbr, 1);
	write(1, " is thinking\n", 13);
	pthread_mutex_unlock(phil->print_mutex);
	return (NULL);
}

void	*print_taken_fork(void *pointer)
{
	struct timeval	curr_time;
	long			diff_time;
	t_phil			*phil;

	gettimeofday(&curr_time, NULL);
	phil = (t_phil *)pointer;
	diff_time = diff_time_calculate(&curr_time, phil->epoch_begin);
	pthread_mutex_lock(phil->print_mutex);
	ft_put_long_nbr_fd(diff_time, 1);
	write(1, " ", 1);
	ft_put_int_nbr_fd(phil->phil_nbr, 1);
	write(1, " has taken a fork\n", 18);
	pthread_mutex_unlock(phil->print_mutex);
	return (NULL);
}

void	print_death(t_phil *phil)
{
	struct timeval	curr_time;
	long			diff_time;

	gettimeofday(&curr_time, NULL);
	diff_time = diff_time_calculate(&curr_time, phil->epoch_begin);
	pthread_mutex_lock(phil->print_mutex);
	ft_put_long_nbr_fd(diff_time, 1);
	write(1, " ", 1);
	ft_put_int_nbr_fd(((t_phil *)phil)->phil_nbr, 1);
	write(1, " died\n", 6);
	phil->is_alive = 0;
}
