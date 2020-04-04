#include "../lemin.h"

int			count_array(const int *array)
{
	int	i;

	if (!array)
		return (0);
	i = 0;
	while (array[i])
		i++;
	return (i);
}

t_rooms		*get_room(t_lemin **lemin, int type, int index)
{
	int		i;

	i = 0;
	while (i < (*lemin)->count_rooms)
	{
		if (type == 1 && (*lemin)->rooms[i]->start)
			return ((*lemin)->rooms[i]);
		else if (type == 2 && (*lemin)->rooms[i]->end)
			return ((*lemin)->rooms[i]);
		else if (type == 3 && (*lemin)->rooms[i]->i == index)
			return ((*lemin)->rooms[i]);
		i++;
	}
	return (0);
}

int			*create_array(int *array, int tunnel)
{
	int i;

	array = (int*)malloc(sizeof(int));
	i = 0;
	while (i < 1)
	{
		array[i] = tunnel;
		i++;
	}
	array[i] = '\0';
	return (array);
}

int			check_in_array(t_lemin *temp, t_rooms *room)
{
	int		i;

	i = 0;
	while (i < temp->count_paths)
	{
		if (temp->paths[i]->prev == room->i)
			return (1);
		i++;
	}
	return (0);
}

int			is_room_in_array(const int *array, int room, int index)
{
	int		i;

	i = 0;
	while (i < index)
	{
		if (array[i] == room)
			return (1);
		i++;
	}
	return (0);
}
