#include "../lemin.h"

int		validation(char *line, t_lemin *lemin)
{
	char	*map;
	char	*join_line;

	map = ft_strdup("");
	while (get_next_line(0, &line) && line)
	{
		join_line = ft_strjoin(line, "\n");
		map = ft_strjoin(map, join_line);
		lemin->map = map;
		if (!lemin->count_ants && check_ants(line, lemin))
			;
		else if (check_commands(line, lemin) || check_comments(line))
			;
		else if (check_spaces(line) && check_room_coordinates(line))
			parse_rooms(line, lemin);
		else if (check_tunnels(line) && check_tunnels_safe(line))
			parse_tunnels(line, lemin);
		else if (check_line_break(line))
			break ;
		else
			return (0);
		free(join_line);
		free(line);
	}
	if (!check_change_tunnel(lemin) || !bad_rooms(&lemin) || empty_struct(&lemin))
		return (0);
	return (1);
}
