#include "../lemin.h"

static void	push_tunnels(t_lemin **lemin, t_tunnel *tunnel)
{
	t_lemin     *temp;
	t_tunnel   **tunnel_temp;
	int         count_room;
	int         i;

	temp = *lemin;
	count_room = temp->count_tunnels + 1;
	i = 0;
	tunnel_temp = (t_tunnel**)malloc(sizeof(t_tunnel) * count_room);
	while (i < count_room)
	{
		if (i == temp->count_tunnels)
			tunnel_temp[i] = tunnel;
		else
			tunnel_temp[i] = temp->tunnels[i];
		i++;
	}
	free(temp->tunnels);
	temp->tunnels = tunnel_temp;
}

int			parse_tunnels(char *line, t_lemin *lemin)
{
	char	    **str;
	t_tunnel	*tunnel;

	str = ft_strsplit(line, '-');
	tunnel = (t_tunnel*)malloc(sizeof(t_tunnel));
	tunnel->start = ft_strdup(str[0]);
	tunnel->end = ft_strdup(str[1]);
	tunnel->start_i = find_room(lemin, str[0]);
	tunnel->end_i = find_room(lemin, str[1]);
	push_tunnels(&lemin, tunnel);
	ft_free_str(str);
	lemin->count_tunnels++;
	return (1);
}
