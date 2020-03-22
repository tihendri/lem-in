#include "../lemin.h"

int		check_change_tunnel(t_lemin *lemin)
{
	int		i;
	int		temp;

	i = 0;
	while (i < lemin->count_tunnels)
	{
		temp = find_room(lemin, lemin->tunnels[i]->end);
		if (temp > -1)
			lemin->tunnels[i]->end_i = temp;
		if (temp == -1)
			return (0);
		temp = find_room(lemin, lemin->tunnels[i]->start);
		if (temp > -1)
			lemin->tunnels[i]->start_i = temp;
		if (temp == -1)
			return (0);
		i++;
	}
	return (1);
}
