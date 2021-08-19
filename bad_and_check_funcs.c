#include "push_swap.h"

int	if_bad_stack(t_list *stack)
{
	free_stack(&stack);
	write(1, "Error\n", 6);
	return (0);
}

int	if_bad_check_digit(int free_flag, char **argv)
{
	if (free_flag)
		free_split(argv);
	return (0);
}

int	check_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
	{
		if (ft_strlen(str) <= 1)
			return (0);
		i++;
	}
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}

void	free_stack(t_list **stack)
{
	t_list	*temp;
	t_list	*to_free;

	temp = *stack;
	while (temp)
	{
		to_free = temp;
		temp = temp->next;
		free(to_free);
	}
}

void	free_split(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		free (argv[i++]);
	free(argv);
}
