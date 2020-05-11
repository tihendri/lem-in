#include "../lemin.h"

static void	push_ants(t_lemin **lemin, t_ants *ants)
{
	t_lemin	*temp;
	int		count;
	t_ants	**ant;
	int		i;

	temp = *lemin;
	count = (int)temp->count_ants + 1;
	ant = (t_ants**)malloc(sizeof(t_ants) * (count) + 1);
	i = -1;
	while (++i < temp->count_ants)
		ant[i] = temp->ants[i];
	ant[i] = ants;
	free(ants);
	// if (temp->count_ants)
	// 	free(temp->ants);
	temp->count_ants++;
	temp->ants = ant;
	free(ant);
}

static void	push_ants_to_strcat(t_lemin **lemin, int path)
{
	t_ants	*ants;

	ants = (t_ants*)malloc(sizeof(t_ants));
	ants->path = -1;
	if (path > -1)
	{
		(*lemin)->go_path[path]->important++;
		ants->path = path;
	}
	ants->sudo_name = 0;
	ants->room = 0;
	ants->move = 0;
	push_ants(lemin, ants);
}

static int	get_ant_path(t_lemin **lemin)
{
	int		i;
	int		j;
	int		i_temp;
	t_lemin	*temp;

	temp = *lemin;
	i = 0;
	j = 0;
	i_temp = -1;
	while (i < temp->count_chosen_path)
	{
		if (!j || temp->go_path[i]->important < j)
		{
			j = temp->go_path[i]->important;
			i_temp = i;
		}
		i++;
	}
	return (i_temp);
}

int			send_ants(t_lemin **lemin)
{
	int		i;
	int		path;
	int		count_ant;
	t_lemin	*temp;

	i = 1;
	temp = *lemin;
	count_ant = (int)temp->count_ants;
	temp->count_ants = 0;
	while (i <= count_ant)
	{
		path = get_ant_path(lemin);
		push_ants_to_strcat(lemin, path);
		i++;
	}
	return (0);
}
