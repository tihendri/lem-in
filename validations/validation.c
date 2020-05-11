#include "../lemin.h"

int		validation(char *line, t_lemin *lemin)
{
	char	*map;
	char	*line_read;

	map = "\0";
	while (get_next_line(0, &line) && line)
	{
		line_read = line;
		free(line);
		map = ft_join_free(map, ft_strjoin(line_read, "\n"), BOTH);
		lemin->map = map;
		free(map);
		if (!lemin->count_ants && check_ants(line_read, lemin))
			;
		else if (check_commands(line_read, lemin) || check_comments(line_read))
			;
		else if (check_spaces(line_read) && check_room_coordinates(line_read))
			parse_rooms(line_read, lemin);
		else if (check_tunnels(line_read) && check_tunnels_safe(line_read))
			parse_tunnels(line_read, lemin);
		else if (check_line_break(line_read))
			break ;
		else
			return (0);
	}
	if (!check_change_tunnel(lemin) || !bad_rooms(&lemin) || empty_struct(&lemin))
		return (0);
	return (1);
}
