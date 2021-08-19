#include "libft.h"
static int	is_in_set(char sym, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
		if (sym == set[i++])
			return (1);
	return (0);
}

static unsigned int	find_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (is_in_set(s1[i], set) && s1[i])
		i++;
	return (i);
}

static unsigned int	find_end(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (is_in_set(s1[i], set) && i > 0)
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	end;
	char			*newstr;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	start = find_start(s1, set);
	end = find_end(s1, set);
	if (start > end || ft_strlen(s1) == 0)
	{
		newstr = (char *) malloc(sizeof(char));
		if (!newstr)
			return (NULL);
		newstr[0] = '\0';
		return (newstr);
	}
	newstr = (char *)malloc(sizeof(*s1) * (end - start + 2));
	if (newstr == NULL)
		return (NULL);
	while (start <= end)
		newstr[i++] = s1[start++];
	newstr[i] = '\0';
	return (newstr);
}
