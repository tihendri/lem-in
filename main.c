#include "lemin.h"

int		main(void)
{
	t_lemin	*lemin;
	t_rooms	*start;
	int		*array;

	struct_populate(&lemin);
	array = NULL;
	if (!validation(0, lemin) || !check_start_end(lemin))
		ft_put_error(lemin, array);
	start = get_room(&lemin, 1, 0);
	if (start->end && start->start)
		ft_put_error(lemin, array);
	find_tunnels_with_rooms(&lemin, start);
	array = (int *)malloc(sizeof(int) * (lemin->count_rooms));
	find_all_paths(&lemin, array, 0, start);
	if (!lemin->count_good)
		ft_put_error(lemin, array);
	find_no_intersecting_paths(&lemin);
	send_ants(&lemin);
	ft_putstr(lemin->map);
	ft_putstr("\n");
	print_ants_on_screen(&lemin, 0);
	freedom(lemin);
	free(lemin);
	free(array);
	return (0);
}
