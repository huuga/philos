#include "philo.h"

t_phil	*lst_findlast(t_phil	*list_of_phil)
{
	if (list_of_phil == NULL)
		return (NULL);
	while (list_of_phil->next)
		list_of_phil = list_of_phil->next;
	return (list_of_phil);
}

void	lst_addback(t_phil **list, t_phil *node)
{
	t_phil	*tmp;

	if (*list == NULL)
	{
		*list = node;
		return ;
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

static int	phil_init(t_phil *phil, t_main_str *main, char **argv)
{
	long	tmp;

	phil->is_alive = 1;
	phil->started_eating = 0;
	phil->locked_forks = 0;
	phil->epoch_begin = &(main->epoch_begin);
	phil->total_num_of_phil = main->numbers_of_phil;
	phil->next = NULL;
	phil->print_mutex = &main->print_mutex;
	phil->forks = main->forks;
	if (argv[5] != NULL)
	{
		tmp = ft_atoi(argv[5]);
		if (tmp == -3000000000)
			return (1);
		phil->times_of_meal = tmp;
	}
	else
		phil->times_of_meal = -1;
	return (0);
}

int	phil_create(t_main_str *main, char **argv, int i)
{
	long	tmp;
	t_phil	*res;

	res = (t_phil *)malloc(sizeof(t_phil));
	if (res == NULL)
		return (1);
	if (phil_init(res, main, argv))
		return (1);
	tmp = ft_atoi(argv[2]);
	if (tmp == -3000000000)
		return (1);
	res->ttd = tmp;
	tmp = ft_atoi(argv[3]);
	if (tmp == -3000000000)
		return (1);
	res->tte = tmp;
	tmp = ft_atoi(argv[4]);
	if (tmp == -3000000000)
		return (1);
	res->tts = tmp;
	res->phil_nbr = i;
	lst_addback(&main->list_of_phil, res);
	return (0);
}
