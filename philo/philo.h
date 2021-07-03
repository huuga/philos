#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int				phil_nbr;
	int				started_eating;
	int				ttd;
	int				tte;
	int				tts;
	int				times_of_meal;
	int				total_num_of_phil;
	int				is_alive;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*forks;
	int				locked_forks;
	struct timeval	*epoch_begin;
	struct s_philo	*next;
}	t_phil;

typedef struct s_main_struct
{
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	int				numbers_of_phil;
	struct timeval	epoch_begin;
	int				curr_phil;
	t_phil			*list_of_phil;
	pthread_mutex_t	*forks;
}	t_main_str;

int				no_args(void);
int				main_st_init(t_main_str *main_st, char **argv);
long			ft_atoi(const	char *str);
int				phil_create(t_main_str *main, char **argv, int i);
pthread_t		*arr_init(int nop);
pthread_mutex_t	*forks_arr_init(int	numbers_of_phil);
void			arr_cleaner(pthread_t **arr, int i);
void			complete_arr_cleaner(pthread_t **arr);
int				numbers_of_philosophers(char *argv);
void			*life_of_phil(void *main);
t_phil			*lst_findlast(t_phil *list_of_phil);
void			*print_sleeping(void *pointer);
void			*print_eating(void *pointer);
void			*print_thinking(void *pointer);
void			*print_taken_fork(void *pointer);
void			print_death(t_phil *phil);
void			forks_search_and_eating(t_phil *phil);
void			forks_release(t_phil *phil);
void			*first_death_timer(void *pointer);
void			*death_timer(void *pointer);
void			first_death(t_phil *phil);
void			death(t_phil *phil);
long			diff_time_calculate(struct timeval *curr_time,
					struct timeval *epoch_begin);
int				even_threads_start(t_main_str *main_st);
int				odd_threads_start(t_main_str *main_st);
void			ft_put_long_nbr_fd(long n, int fd);
void			ft_put_int_nbr_fd(int n, int fd);
#endif
