#include "../lemin.h"

int		check_start_end(t_lemin *lemin)
{
	if (lemin->start_room != 1 || lemin->end_room != 1)
		return (0);
	return (1);
}