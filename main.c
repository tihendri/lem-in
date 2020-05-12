#include "lemin.h"

void	struct_populate(t_lemin **lemin)
{
	t_lemin *temp;

	temp = (t_lemin*)malloc(sizeof(t_lemin));
	temp->start_room = 0;
	temp->end_room = 0;
	temp->map = 0;
	temp->print = 0;
	temp->last_name = 0;
	temp->start_move = 0;
	temp->end_move = 0;
	temp->count_ants = 0;
	temp->count_rooms = 0;
	temp->count_tunnels = 0;
    temp->count_paths = 0;
	temp->count_good = 0;
	temp->count_chosen_path = 0;
	temp->ants = 0;
	temp->rooms = 0;
	temp->tunnels = 0;
	temp->paths = 0;
	temp->good_path = 0;
	temp->go_path = 0;
	*lemin = temp;
}

int		main(void)
{
	t_lemin	*lemin;
	t_rooms	*start;
	int		*array;

	struct_populate(&lemin);
	if (!validation(0, lemin) || !check_start_end(lemin))
		ft_put_error();
	start = get_room(&lemin, 1, 0);
	if (start->end && start->start)
		ft_put_error();
	find_tunnels_with_rooms(&lemin, start);
	array = (int *)malloc(sizeof(int) * (lemin->count_rooms));
	find_all_paths(&lemin, array, 0, start);
	if (!lemin->count_good)
		ft_put_error();
	find_no_intersecting_paths(&lemin);
	send_ants(&lemin);
	ft_putstr(lemin->map);
	ft_putstr("\n");
	print_ants_on_screen(&lemin, 0);
	return (0);
}
