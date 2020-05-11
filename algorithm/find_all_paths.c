#include "../lemin.h"

static void	push_others_paths(t_lemin **set, t_path *path)
{
	t_lemin     *temp;
	t_path    **arr;
	int         count;
	int         i;

	temp = *set;
	count = temp->count_good + 1;
	arr = (t_path**)malloc(sizeof(t_path*) * (count + 1));
	i = -1;
	while (++i < temp->count_good)
		arr[i] = temp->good_path[i];
	arr[i] = path;
	temp->count_good++;
	// free(temp->good_path);
	temp->good_path = arr;
	free(arr);
}

int			push_first_path(const int *arr, t_lemin **lemin, int length)
{
	t_path   *good_path;
	int             i;

	i = -1;
	good_path = (t_path *)malloc(sizeof(t_path));
	good_path->path = (int *)malloc(sizeof(int) * (length) + 1);
	good_path->length = length;
	good_path->important = length;
	while (++i < length)
		good_path->path[i] = arr[i];
	push_others_paths(lemin, good_path);
	free(good_path->path);
	free(good_path);
	return (0);
}

static void	find_all_paths_min(t_lemin *temp, t_rooms *start, int i_curr_pos, int *arr)
{
	t_rooms	*room;
	int		k;
	int		count;
	int		i;

	i = 0;
	k = 0;
	count = temp->count_paths;
	while (i < count)
	{
		if (start->i == temp->paths[i]->prev)
		{
			while (k < temp->paths[i]->length)
			{
				room = get_room(&temp, 3, temp->paths[i]->path[k]);
				if (!is_room_in_array(arr, temp->paths[i]->path[k], i_curr_pos + 1))
					find_all_paths(&temp, arr, i_curr_pos + 1, room);
				k++;
			}
		}
		i++;
	}
}

int			find_all_paths(t_lemin **lemin, int *arr, int i_curr_pos, t_rooms *start)
{
	t_lemin *temp;

	temp = *lemin;
	arr[i_curr_pos] = start->i;
	if (start->end)
		return (push_first_path(arr, lemin, i_curr_pos + 1));
	find_all_paths_min(temp, start, i_curr_pos, arr);
	return (0);
}
