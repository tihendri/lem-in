#include "../lemin.h"

void		ft_put_error()
{
	ft_putstr("\033[1;31mERROR\n");
	exit(-1);
}

void		ft_put_error_only_lemin(t_lemin *lemin)
{
	if (lemin)
		free(lemin);
	ft_putstr("\033[1;31mERROR\n");
	exit(-1);
}