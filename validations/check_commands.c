#include "../lemin.h"

int		check_commands(char *line, t_lemin *lemin)
{
	if (line[0] == '#' && line[1] == '#')
	{
		if (ft_strequ("##start", line) &&
				lemin->start_move != 2 && lemin->start_move != 1)
			lemin->start_move = 1;
		else if (ft_strequ("##start", line)
				&& (lemin->start_move == 2 || lemin->start_move == 1))
			return (0);
		if (ft_strequ("##end", line) && lemin->end_move != 2
				&& lemin->end_move != 1)
			lemin->end_move = 1;
		else if (ft_strequ("##end", line)
				&& (lemin->end_move == 2 || lemin->end_move == 1))
			return (0);
		return (1);
	}
	return (0);
}
