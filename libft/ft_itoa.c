#include "libft.h"

static int	string_size(int n)
{
	int	size;

	size = 0;
	if (n < 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static char	*if_zero(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		str_size;
	int		mlp;

	mlp = 1;
	if (n == 0)
		return (if_zero());
	str_size = string_size(n);
	str = (char *)malloc(sizeof(char) * (str_size + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		mlp = -1;
	}
	str[str_size--] = '\0';
	while (n != 0)
	{
		str[str_size--] = mlp * (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
