#include "philo.h"

int	main(int argc, char **argv)
{
	int				i;
	t_main_str		main_st;
	t_phil			*dead_listener;

	if (argc != 5 && argc != 6)
		return (no_args());
	if (main_st_init(&main_st, argv))
		return (1);
	i = 0;
	while (i++ < main_st.numbers_of_phil)
		if (phil_create(&main_st, argv, i))
			return (1);
	if (odd_threads_start(&main_st))
		return (1);
	if (even_threads_start(&main_st))
		return (1);
	dead_listener = main_st.list_of_phil;
	while (dead_listener->is_alive)
		dead_listener = dead_listener->next;
	return (0);
}
