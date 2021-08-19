#include "libft.h"
char	*ft_strchr(const char *string, int symbol)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == (unsigned char)symbol)
			return (&((char *)string)[i]);
		i++;
	}
	if (symbol == '\0')
		return (&((char *)string)[i]);
	else
		return (NULL);
}
