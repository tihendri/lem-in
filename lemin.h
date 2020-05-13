#ifndef LEMIN_H
#define LEMIN_H

#include "libft/libft.h"

// typedef enum	e_del
// {
// 	FIRST,
// 	SECOND,
// 	BOTH
// }				t_del;

typedef struct	s_rooms
{
	char		*title;
	int			i;
	int			start;
	int			end;
}				t_rooms;


/*
**Tunnels refer to links between rooms.
**Paths refer to the direction to the tunnels.
*/

typedef struct	s_tunnel
{
	char		*start;
	char		*end;
	int			start_i;
	int			end_i;
}				t_tunnel;

typedef struct	s_path
{
	int			*path;
	int			important;
	int			length;
	int			prev;
}				t_path;

typedef struct	s_ants
{
	int			sudo_name;
	int			path;
	int			room;
	int			move;
}				t_ants;

typedef struct	s_lemin
{
	int			start_room;
	int			end_room;
	char		*map;
	int			print;
	int			last_name;
	int			start_move;
	int			end_move;
	int			count_ants;
    int			count_rooms;
	int			count_tunnels;
	int			count_paths;
	int			count_good;
	int			count_chosen_path;
	t_ants      **ants;
	t_rooms		**rooms;
	t_tunnel	**tunnels;
	t_path  	**paths;
	t_path  	**good_path;
	t_path  	**go_path;
}				t_lemin;

char    		*ft_join_free(char *str1, char *str2);
int				bad_rooms(t_lemin **lemin);
int     		check_ants(char *line, t_lemin *lemin);
int     		check_change_tunnel(t_lemin *lemin);
int     		check_commands(char *line, t_lemin *lemin);
int     		check_comments(const char *line);
int 			check_in_array(t_lemin *temp, t_rooms *room);
int     		check_line_break(const char *line);
int				check_room_coordinates(char *line);
int     		check_spaces(const char *line);
int     		check_start_end(t_lemin *lemin);
int				check_tunnels(char *line);
int				check_tunnels_safe(const char *line);
int             count_array(const int *array);
int 			*create_array(int *array, int tunnel);
int     		empty_struct(t_lemin **lemin);
int 			find_all_paths(t_lemin **lemin, int *arr, int i_curr_pos, t_rooms *start);
int 			find_room(t_lemin *lemin, char *room);
int	    		find_tunnels_with_rooms(t_lemin **lemin, t_rooms *start);
int 			is_room_in_array(const int *array, int room, int index);
int 			parse_rooms(char *line, t_lemin *lemin);
int 			parse_tunnels(char *line, t_lemin *lemin);
int     		print_ants(t_lemin **lemin, int ant, char *room);
int			    push_first_path(const int *arr, t_lemin **lemin, int length);
int 			send_ants(t_lemin **lemin);
int     		validation(char *line, t_lemin *lemin);
t_rooms		    *get_room(t_lemin **lemin, int type, int index);
void    		find_no_intersecting_paths(t_lemin **lemin);
void    		free_str(char **str);
void    		ft_put_error();
void			print_ants_on_screen(t_lemin **lemin, int i);
#endif
