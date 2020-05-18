#include "lemin.h"

void	struct_populate(t_lemin **lemin)
{
	t_lemin *temp;

	temp = (t_lemin*)malloc(sizeof(t_lemin));
	temp->start_room = 0;
	temp->end_room = 0;
	temp->map = 0;
	temp->print = 0;
	temp->last_name = 0;
	temp->start_move = 0;
	temp->end_move = 0;
	temp->count_ants = 0;
	temp->count_rooms = 0;
	temp->count_tunnels = 0;
    temp->count_paths = 0;
	temp->count_good = 0;
	temp->count_chosen_path = 0;
	temp->ants = 0;
	temp->rooms = 0;
	temp->tunnels = 0;
	temp->paths = 0;
	temp->good_path = 0;
	temp->go_path = 0;
	*lemin = temp;
}

void	free_tunnel(t_tunnel *tunnel)
{
	if (*tunnel->start)
		free(tunnel->start);
	if (*tunnel->end)
		free(tunnel->end);
}

void	free_room(t_rooms *rooms)
{
	if (*rooms->title)
		free(rooms->title);
}

void	free_path(t_path *pathenon)
{
	if (*pathenon->path)
		free(pathenon->path);
}

void	freedom(t_lemin *lemin)
{
	int 		i;
	t_rooms		*room_t;
	t_tunnel	*tunnel_t;
	t_path		*path_t;
	t_path		*path_ti;
	t_path		*path_tim;

	i = 0;
	while (lemin->count_ants > i)
	{
		free(lemin->ants[i]);
		i++;
	}
	i = 0;
	free(lemin->ants);
	while (lemin->count_rooms > i)
	{
		room_t = lemin->rooms[i];
		free_room(room_t);
		free(lemin->rooms[i]);
		i++;
	}
	i = 0;
	free(lemin->rooms);
	while (lemin->count_tunnels > i)
	{
		tunnel_t = lemin->tunnels[i];
		free_tunnel(tunnel_t);
		free(lemin->tunnels[i]);
		i++;
	}
	i = 0;
	free(lemin->tunnels);
	while (lemin->count_paths > i)
	{
		path_t = lemin->paths[i];
		free_path(path_t);
		free(lemin->paths[i]);
		i++;
	}
	free(lemin->map);
	i = 0;
	while (lemin->count_good > i)
	{
		path_tim = lemin->good_path[i];
		free_path(path_tim);
		free(lemin->good_path[i]);
		i++;
	}
	free(lemin->good_path);
	free(lemin->paths);
	while (lemin->count_chosen_path > i)
	{
		path_ti = lemin->go_path[i];
		free_path(path_ti);
		free(lemin->go_path[i]);
		i++;
	}
	free(lemin->go_path);
}

int		main(void)
{
	t_lemin	*lemin;
	t_rooms	*start;
	int		*array;

	struct_populate(&lemin);
	if (!validation(0, lemin) || !check_start_end(lemin))
		ft_put_error();
	start = get_room(&lemin, 1, 0);
	if (start->end && start->start)
		ft_put_error();
	find_tunnels_with_rooms(&lemin, start);
	array = (int *)malloc(sizeof(int) * (lemin->count_rooms));
	find_all_paths(&lemin, array, 0, start);
	if (!lemin->count_good)
		ft_put_error();
	find_no_intersecting_paths(&lemin);
	send_ants(&lemin);
	ft_putstr(lemin->map);
	ft_putstr("\n");
	print_ants_on_screen(&lemin, 0);
	freedom(lemin);
	free(lemin);
	free(array);
	return (0);
}
