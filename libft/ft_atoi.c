#include "libft.h"
int	is_space(int symbol)
{
	if (symbol == '\r' || symbol == '\f' || symbol == '\v'
		|| symbol == '\n' || symbol == '\t' || symbol == ' ')
		return (1);
	else
		return (0);
}

int	mlp_finder(int symbol)
{
	if (symbol == '-')
		return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	mlp;
	int	num;

	i = 0;
	mlp = 1;
	num = 0;
	while (is_space(str[i]))
		i++;
	if ((str[i] == '-' ) || (str[i] == '+'))
	{
		mlp = mlp_finder(str[i]);
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (mlp * num);
}
