#include "../lemin.h"

int		check_spaces(const char *line)
{
	int	i;
	int	count_space;

	i = 0;
	count_space = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			count_space++;
		i++;
	}
	if (count_space == 2)
		return (1);
	return (0);
}
