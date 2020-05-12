#include "../lemin.h"

static void	push_other_rooms(t_lemin **lemin, t_rooms *room)
{
	t_lemin	*temp;
	t_rooms	**rooms;
	int		count_room;
	int		i;

	temp = *lemin;
	count_room = temp->count_rooms + 1;
	i = 0;
	rooms = (t_rooms**)malloc(sizeof(t_rooms) * count_room);
	while (i < count_room)
	{
		if (i == temp->count_rooms)
			rooms[i] = room;
		else
			rooms[i] = temp->rooms[i];
		i++;
	}
	free(temp->rooms);
	temp->rooms = rooms;
}

int			parse_rooms(char *line, t_lemin *lemin)
{
	char	**str;
	t_rooms	*room;

	str = ft_strsplit(line, ' ');
	room = (t_rooms*)malloc(sizeof(t_rooms));
	room->title = ft_strdup(str[0]);
	room->start = 0;
	room->end = 0;
	room->i = lemin->count_rooms + 1;
	push_other_rooms(&lemin, room);
	if (lemin->end_move == 1)
	{
		room->end = 1;
		lemin->end_move = 2;
		lemin->end_room = 1;
	}
	if (lemin->start_move == 1)
	{
		room->start = 1;
		lemin->start_move = 2;
		lemin->start_room = 1;
	}
	ft_free_str(str);
	lemin->count_rooms++;
	return (1);
}
