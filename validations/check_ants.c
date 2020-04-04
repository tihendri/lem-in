#include "../lemin.h"
int		check_ants(char *line, t_lemin *lemin)
{
	int				i;
	long long int	ants;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	ants = ft_atoi(line);
	if (ants > 0)
		lemin->count_ants = (int)ants;
	if (ants >= 2147483648)
		return (0);
	return (1);
}
