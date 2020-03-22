#include "../lemin.h"

int		empty_struct(t_lemin **lemin)
{
	t_lemin	*temp;

	temp = *lemin;
	if (!temp->count_ants || !temp->count_rooms || !temp->count_tunnels)
		return (1);
	return (0);
}