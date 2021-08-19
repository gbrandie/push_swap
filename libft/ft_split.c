#include "libft.h"
static unsigned int	find_words(char const *s, char c)
{
	unsigned int	i;
	unsigned int	words;

	i = 0;
	words = 1;
	if (ft_strlen(s) == 0)
		return (0);
	if (s[0] == c)
		words--;
	while (s[i])
	{
		if (s[i] == c)
		{
			words++;
			while (s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] == c)
		words--;
	return (words);
}

static unsigned int	find_start_index(char const *s, \
									char c, unsigned int start_pos)
{
	while (s[start_pos] == c && s[start_pos])
		start_pos++;
	return (start_pos);
}

static unsigned int	wordlen(char const *s, char c, unsigned int start_pos)
{
	int	i;

	i = 0;
	while (s[start_pos] != c && s[start_pos])
	{
		start_pos++;
		i++;
	}
	return (i);
}

static char	**create_array(char const *s, char **arr, char c, \
												unsigned int start_pos)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (j < find_words(s, c))
	{
		arr[j] = (char *)malloc(sizeof(*s) * (wordlen(s, c, start_pos) + 1));
		if (!arr[j])
		{
			i = 0;
			while (i < j)
				free(arr[i++]);
			free(arr);
			return (NULL);
		}
		while (s[start_pos] != c && s[start_pos])
			arr[j][i++] = s[start_pos++];
		arr[j][i] = '\0';
		j++;
		i = 0;
		start_pos = find_start_index(s, c, start_pos);
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	start_pos;
	unsigned int	words;
	char			**arr;

	if (s == 0)
		return (NULL);
	start_pos = find_start_index(s, c, 0);
	words = find_words(s, c);
	if (words == 0)
	{
		arr = (char **)malloc(sizeof(char *));
		arr[0] = NULL;
		return (arr);
	}
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	arr = create_array(s, arr, c, start_pos);
	arr[words] = NULL;
	return (arr);
}
