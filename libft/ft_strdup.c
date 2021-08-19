#include "libft.h"
char	*ft_strdup(const char *src)
{
	char	*dst;
	int		src_len;
	int		i;

	i = 0;
	src_len = ft_strlen((char *)src);
	dst = (char *)malloc((src_len + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
