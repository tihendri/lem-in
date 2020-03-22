#include "../lemin.h"

int		check_comments(const char *line)
{
	if (line[0] == '#' && line[1] != '#')
		return (1);
	return (0);
}