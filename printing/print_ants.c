#include "../lemin.h"

int		print_ants(t_lemin **lemin, int ant, char *room)
{
	t_lemin *temp;

	temp = *lemin;
	if (temp->print)
		ft_putstr(" ");
	ft_putstr("\033[0;31mL\033[1;31m");
	ft_putnbr(ant);
	ft_putstr("\033[0;33m-\033[1;32m");
	ft_putstr(room);
	return (1);
}
