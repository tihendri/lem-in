#include "../lemin.h"

int		check_line_break(const char *line)
{
	if (!line[0])
		return (1);
	if (line[0] == '\n' && line[1] == '\n')
		return (1);
	if (line[0] == '\n' && line[1] == '\0')
		return (1);
	return (0);
}