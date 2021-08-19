#include "libft.h"
int	func_strcmp(const char *string, const char *substring, size_t start_index)
{
	size_t	i;

	i = 0;
	while (substring[i] != '\0')
	{
		if (substring[i] != string[start_index + i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *string, const char *substring, size_t len)
{
	size_t	last_index;
	size_t	substring_end_index;
	size_t	start_index;
	size_t	i;
	size_t	cmp_sum;

	if (!ft_strlen(string) && !ft_strlen(substring))
		return ("");
	if (!ft_strlen(substring))
		return ((char *)string);
	start_index = 0;
	cmp_sum = 0;
	last_index = ft_strlen(string);
	substring_end_index = ft_strlen(substring);
	while (substring_end_index <= last_index && substring_end_index - 1 < len)
	{
		i = 0;
		if (func_strcmp(string, substring, start_index))
			return (&((char *)string)[start_index]);
		cmp_sum = 0;
		start_index++;
		substring_end_index++;
	}
	return (NULL);
}
