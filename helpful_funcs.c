#include "push_swap.h"

int	get_number(const char *str)
{
	int	i;
	int	return_value;
	int	minus;

	i = 0;
	minus = 1;
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	return_value = 0;
	while (str[i])
		return_value = return_value * 10 + str[i++] - '0';
	return (minus * return_value);
}

int	is_space(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i++] == ' ')
			return (1);
	return (0);
}

int list_len(t_list *list)
{
	int i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}