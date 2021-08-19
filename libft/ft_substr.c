#include "libft.h"
static int	find_malloc_size(char const *s, unsigned int start, size_t len)
{
	if (ft_strlen(s) - start + 1 > len + 1)
		return (len + 1);
	else
		return (ft_strlen(s) - start + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	int				malloc_size;

	if (!s)
		return (NULL);
	malloc_size = find_malloc_size(s, start, len);
	i = ft_strlen(s);
	if (start >= i)
	{
		substr = (char *)(malloc(sizeof(*s)));
		if (substr == NULL)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	i = 0;
	substr = (char *) malloc(sizeof(char) * malloc_size);
	if (!substr)
		return (NULL);
	while (s[start] && len--)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
