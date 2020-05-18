#include "../lemin.h"

static void	free_tunnel(t_tunnel *tunnel)
{
	if (*tunnel->start)
		free(tunnel->start);
	if (*tunnel->end)
		free(tunnel->end);
}

static void	free_room(t_rooms *rooms)
{
	if (*rooms->title)
		free(rooms->title);
}

static void	free_path(t_path *pathenon)
{
	if (*pathenon->path)
		free(pathenon->path);
}

void	    freedom(t_lemin *lemin)
{
	int 		i;
	t_rooms		*room_t;
	t_tunnel	*tunnel_t;
	t_path		*path_t;
	t_path		*path_tim;

	i = 0;
	if (lemin->ants != 0)
	{
		while (lemin->count_ants > i)
		{
			free(lemin->ants[i]);
			i++;
		}
		free(lemin->ants);
	}
	i = 0;
	if (lemin->rooms != 0)
	{
		while (lemin->count_rooms > i)
		{
			room_t = lemin->rooms[i];
			free_room(room_t);
			free(lemin->rooms[i]);
			i++;
		}
		free(lemin->rooms);
	}
	i = 0;
	if (lemin->tunnels != 0)
	{
		while (lemin->count_tunnels > i)
		{
			tunnel_t = lemin->tunnels[i];
			free_tunnel(tunnel_t);
			free(lemin->tunnels[i]);
			i++;
		}
		free(lemin->tunnels);
	}
	i = 0;
	if (lemin->count_paths != 0)
	{
		while (lemin->count_paths > i)
		{
			path_t = lemin->paths[i];
			free_path(path_t);
			free(lemin->paths[i]);
			i++;
		}
		free(lemin->paths);
	}
	free(lemin->map);
	i = 0;
	if (lemin->good_path != 0)
	{
		while (lemin->count_good > i)
		{
			path_tim = lemin->good_path[i];
			free_path(path_tim);
			free(lemin->good_path[i]);
			i++;
		}
		free(lemin->good_path);
	}
	if (lemin->go_path != 0)
		free(lemin->go_path);
}