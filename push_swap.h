#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_list
{
	int				data;
	int				pos;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

t_list		*create_node(int data);
void		append_end(t_list **list, int pos, int value);
int			get_number(const char *str);
int			is_space(const char *str);
int			array_len(char **arr);
void		free_stack(t_list **stack);
void		free_split(char **argv);
int			check_digit(char *str);
int			if_bad_check_digit(int free_flag, char **argv);
int			create_stack(t_list **A, int argc, char **argv);
int			if_bad_stack(t_list *stack);
int			list_len(t_list *list);

#endif
