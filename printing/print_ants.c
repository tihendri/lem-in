#include "../lemin.h"

int		print_ants(t_lemin **lemin, int ant, char *room)
{
	t_lemin *temp;

	temp = *lemin;
	if (temp->print)
		printf(" ");
	printf("\033[31mL\033[0m");
	printf("\033[31m%d\033[0m", ant);
	printf("\033[0;33m-\033[0;33m");
	printf("\033[32m%s\033[32m", room);
	return (1);
}
