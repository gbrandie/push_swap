#include "libft.h"
void	ft_bzero(void *dst, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)dst)[i] = 0;
		i++;
	}
}
