#include "../lemin.h"

void		ft_put_error(t_lemin *lemin, int *array)
{
	ft_putstr("\033[1;31mERROR\n");
	if (array != NULL)
		free(array);
	freedom(lemin);
	free(lemin);
	exit(EXIT_FAILURE);
}