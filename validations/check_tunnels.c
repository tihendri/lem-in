#include "../lemin.h"

static	int		check_room(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && !ft_isalpha(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int				check_tunnels_safe(const char *line)
{
	int i;
	int safe_to_go;

	i = 0;
	safe_to_go = 0;
	while (line[i])
	{
		if (line[i] == '-')
			safe_to_go++;
		i++;
	}
	if (safe_to_go == 1)
		return (1);
	return (0);
}

int				check_tunnels(char *line)
{
	int		i;
	char	**str;

	i = 0;
	str = ft_strsplit(line, '-');
	while (str[i])
	{
		if (!check_room(str[i]))
			return (0);
		i++;
	}
	if (i == 2)
		return (1);
	return (0);
}
