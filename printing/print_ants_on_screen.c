#include "../lemin.h"

static void		update_movement(t_lemin **lemin)
{
	t_lemin	*temp;
	int		i;

	temp = *lemin;
	i = 0;
	while (i < temp->count_ants)
	{
		if (temp->ants[i]->move != 3)
			temp->ants[i]->move = 0;
		i++;
	}
}

static int		check_last_ant(int path, int room, t_lemin **lemin, t_rooms *finish)
{
	int		i;
	t_lemin	*temp;

	i = 0;
	temp = *lemin;
	while (i < temp->count_ants)
	{
		if (temp->ants[i]->room == room
				&& !finish->end && temp->ants[i]->path == path)
			return (0);
		i++;
	}
	return (1);
}

static void		print_one_ant(t_lemin **lemin, t_ants *ant)
{
	t_lemin	*temp;
	int		path;
	int		j;
	t_rooms	*room;

	temp = *lemin;
	ant->move = 2;
	path = ant->path;
	j = ant->room + 1;
	room = get_room(lemin, 3, temp->go_path[path]->path[j]);
	if (ant->move == 2 && check_last_ant(path, j, &temp, room))
	{
		if (room->end)
			ant->move = 3;
		else
			ant->move = 1;
		if (!ant->sudo_name)
		{
			ant->sudo_name = temp->last_name + 1;
			temp->last_name += 1;
		}
		if (print_ants(lemin, ant->sudo_name, room->title))
			temp->print++;
		ant->room = j;
	}
}

static t_ants	*get_right_ant(t_lemin **lemin, int name)
{
	int		i;
	t_lemin	*temp;

	i = 0;
	temp = *lemin;
	while (i < temp->count_ants)
	{
		if (temp->ants[i]->sudo_name == name && temp->ants[i]->move != 2)
			return (temp->ants[i]);
		i++;
	}
	i = 0;
	while (i < temp->count_ants)
	{
		if (!temp->ants[i]->room && temp->ants[i]->move != 2)
			return (temp->ants[i]);
		i++;
	}
	return (temp->ants[name]);
}

void			print_ants_on_screen(t_lemin **lemin, int i)
{
	t_lemin	*temp;
	int		ants;
	t_ants	*ant;

	temp = *lemin;
	ants = 0;
	while (i < temp->count_ants)
	{
		ant = get_right_ant(lemin, i + 1);
		if (ant->move != 3)
			print_one_ant(&temp, ant);
		else
			ants++;
		i++;
	}
	update_movement(&temp);
	temp->print = 0;
	if (ants != temp->count_ants)
	{
		printf("\n");
		print_ants_on_screen(&temp, 0);
	}
}
