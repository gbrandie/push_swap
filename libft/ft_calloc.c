#include "libft.h"
void	*ft_calloc(size_t count, size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	new = malloc(size * count);
	if (new == NULL)
		return (NULL);
	while (i < count * size)
	{
		new[i] = 0;
		i++;
	}
	return (new);
}
