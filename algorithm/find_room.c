#include "../lemin.h"

int			find_room(t_lemin *lemin, char *room)
{
	int	i;

	i = 0;
	while (i < lemin->count_rooms)
	{
		if (ft_strequ(room, lemin->rooms[i]->title))
			return (lemin->rooms[i]->i);
		i++;
	}
	return (-1);
}
