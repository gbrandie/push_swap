#include "libft.h"
int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if (((unsigned char *)buf1)[i] != ((unsigned char *)buf2)[i])
			return (((unsigned char *)buf1)[i] - ((unsigned char *)buf2)[i]);
		i++;
	}
	return (0);
}
