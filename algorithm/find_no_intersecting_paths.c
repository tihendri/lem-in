#include "../lemin.h"

static void	push_to_path_force(t_lemin **lemin, t_path *path)
{
	t_lemin         *temp;
	int             count;
	t_path   **path_to_choose;
	int             i;

	temp = *lemin;
	count = temp->count_chosen_path + 1;
	path_to_choose = (t_path**)malloc(sizeof(t_path) * count);
	path->important = path->length;
	i = -1;
	while (++i < temp->count_chosen_path)
		path_to_choose[i] = temp->go_path[i];
	path_to_choose[i] = path;
	temp->count_chosen_path++;
	// free(temp->go_path);
	temp->go_path = path_to_choose;
	free(path_to_choose);
}

static int	check_room_in_array(t_lemin **lemin, int index)
{
	int		i;
	int		j;
	int		test;
	t_lemin *temp;

	i = 0;
	temp = *lemin;
	while (i < temp->count_chosen_path)
	{
		j = 1;
		while (j < (temp->go_path[i]->length - 1))
		{
			test = temp->go_path[i]->path[j];
			if (index == test)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	validate_intersecting(t_lemin **lemin, int index)
{
	int		i;
	int		test;
	t_lemin	*temp;

	i = 1;
	temp = *lemin;
	while (i < (temp->good_path[index]->length - 1))
	{
		test = temp->good_path[index]->path[i];
		if (check_room_in_array(lemin, test))
			return (1);
		i++;
	}
	return (0);
}

static void	check_intersecting_path(t_lemin **lemin)
{
	int		i;
	int		not_good;
	t_lemin	*temp;

	i = 0;
	temp = *lemin;
	while (i < temp->count_good)
	{
		if (!validate_intersecting(lemin, i))
		{
			not_good = i;
			push_to_path_force(lemin, temp->good_path[not_good]);
		}
		i++;
	}
}

void		find_no_intersecting_paths(t_lemin **lemin)
{
	int		i;
	int		temp_i;
	int		j;
	t_lemin	*temp;

	temp = *lemin;
	i = 0;
	j = 0;
	temp_i = 0;
	while (i < temp->count_good)
	{
		if (!j || temp->good_path[i]->length < j)
		{
			temp_i = i;
			j = temp->good_path[i]->length;
		}
		i++;
	}
	push_to_path_force(lemin, temp->good_path[temp_i]);
	check_intersecting_path(lemin);
}
