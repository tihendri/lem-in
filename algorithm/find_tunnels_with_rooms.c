#include "../lemin.h"

static int	push_tunnel_to_strcat(t_lemin **lemin, int *array, t_rooms *room)
{
	t_lemin     *temp;
	t_path      *path;
	t_path      **path_arr;
	int         count;
	int         i;

	temp = *lemin;
	path = (t_path*)malloc(sizeof(t_path));
	path->length = count_array(array);
	path->path = array;
	path->prev = room->i;
	count = temp->count_paths + 1;
	i = 0;
	path_arr = (t_path**)malloc(sizeof(t_path) * count);
	while (i < count)
	{
		if (i == temp->count_paths)
			path_arr[i] = path;
		else
			path_arr[i] = temp->paths[i];
		i++;
	}
	free(path);
	// free(temp->paths);
	temp->paths = path_arr;
	free(path_arr);
	return (1);
}

static int	*add_to_array(int *array, int tunnel)
{
	int i;
	int count;
	int *temp;

	i = -1;
	count = count_array(array);
	if (!count)
		return (create_array(array, tunnel));
	temp = (int*)malloc(sizeof(int) * (count + 2));
	while (array[++i])
		temp[i] = array[i];
	temp[i] = tunnel;
	temp[i + 1] = 0;
	free(array);
	return (temp);
}

static int	*find_tunnel(t_lemin **lemin, int room, int *array)
{
	int		i;
	t_lemin	*temp;

	i = 0;
	temp = *lemin;
	while (i < temp->count_tunnels)
	{
		if (temp->tunnels[i]->start_i == room)
			array = add_to_array(array, temp->tunnels[i]->end_i);
		else if (temp->tunnels[i]->end_i == room)
			array = add_to_array(array, temp->tunnels[i]->start_i);
		i++;
	}
	return (array);
}

int			find_tunnels_with_rooms(t_lemin **lemin, t_rooms *start)
{
	t_lemin	*temp;
	int		*array;
	int		i;
	t_rooms	*room;

	i = 0;
	array = 0;
	temp = *lemin;
	array = find_tunnel(&temp, start->i, array);
	if (push_tunnel_to_strcat(&temp, array, start))
		temp->count_paths++;
	while (array[i])
	{
		room = get_room(&temp, 3, array[i]);
		if (!room->end && !check_in_array(temp, room))
		{
			// free(array);
			find_tunnels_with_rooms(lemin, room);
		}
		i++;
	}
	free(array);
	return (0);
}
