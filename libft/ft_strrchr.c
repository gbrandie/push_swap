#include "libft.h"
char	*ft_strrchr(const char *string, int symbol)
{
	int	i;

	i = ft_strlen(string);
	while (i >= 0)
	{
		if (string[i] == (unsigned char)symbol)
			return (&((char *)string)[i]);
		i--;
	}
	return (NULL);
}
