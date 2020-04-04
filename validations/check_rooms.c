#include "../lemin.h"

static	int		check_room(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && !ft_isalpha(line[i]))
			return (0);
		if (line[0] == 'L')
			return (0);
		i++;
	}
	return (1);
}

static	int		check_coordinates(char *line)
{
	int				i;
	long long int	coordinates;

	i = 0;
	coordinates = ft_atoi(line);
	while (line[i])
	{
		if (!ft_isdigit(line[i]) || coordinates >= 2147483648)
			return (0);
		i++;
	}
	return (1);
}

int				check_room_coordinates(char *line)
{
	int		i;
	char	**str;

	i = 0;
	str = ft_strsplit(line, ' ');
	while (str[i])
	{
		if (i == 0)
		{
			if (!check_room(str[i]))
				return (0);
		}
		else
		{
			if (!check_coordinates(str[i]))
				return (0);
		}
		i++;
	}
	if (i == 3)
	{
		ft_free_str(str);
		return (1);
	}
	return (0);
}

static int		bad_room_min(t_lemin **lemin, int index)
{
	int		i;
	int		start;
	int		finish;
	int		err;
	t_lemin	*temp;

	temp = *lemin;
	i = 0;
	err = 0;
	while (i < temp->count_tunnels)
	{
		start = temp->tunnels[i]->start_i;
		finish = temp->tunnels[i]->end_i;
		if (start == index)
			err++;
		if (finish == index)
			err++;
		i++;
	}
	if (!err)
		return (0);
	return (1);
}

int				bad_rooms(t_lemin **lemin)
{
	int		i;
	t_lemin	*temp;

	i = 0;
	temp = *lemin;
	while (i < temp->count_rooms)
	{
		if (!bad_room_min(lemin, (*lemin)->rooms[i]->i))
			return (0);
		i++;
	}
	return (1);
}
