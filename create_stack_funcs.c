#include "push_swap.h"

t_list	*create_node(int data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	append_end(t_list **list, int pos, int value)
{
	t_list	*temp;
	t_list	*new_elem;

	temp = *list;
	new_elem = create_node(value);
	if (pos == 0)
	{
		*list = new_elem;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new_elem;
	new_elem->prev = temp;
}

int	create_stack(t_list **A, int argc, char **argv)
{
	int	i;
	int	free_flag;

	free_flag = 0;
	if (is_space(argv[0]))
	{
		argv = ft_split(argv[0], ' ');
		argc = array_len(argv);
		free_flag = 1;
	}
	i = 0;
	while (i < argc)
	{
		if (!check_digit(argv[i]))
			return (if_bad_check_digit(free_flag, argv));
		append_end(A, i, get_number(argv[i]));
		i++;
	}
	if (free_flag)
		free_split(argv);
	return (1);
}

int	array_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
