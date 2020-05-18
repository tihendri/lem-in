#include "../lemin.h"

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