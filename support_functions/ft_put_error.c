#include "../lemin.h"

void		ft_put_error(void)
{
	write(1, "ERROR\n", 6);
	exit(-1);
}