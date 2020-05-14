#include "../lemin.h"

int		validation(char *line, t_lemin *lemin)
{
	char	*join_line;

	lemin->map = (char *)malloc(sizeof(char) * 2048 * 32);
	while (get_next_line(0, &line) && line)
	{
		join_line = ft_strjoin(line, "\n");
		lemin->map = ft_strcat(lemin->map, join_line);
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
