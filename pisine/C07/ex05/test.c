#include <stdlib.h>

int	check_charset(char a, char *charset)
{
	int	i;
	i = 0;
	while (charset[i] != '\0')
	{
		if (a == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (check_charset(str[i], charset) == 0 && \
				check_charset(str[i + 1], charset) == 1) 
			count = count + 1;
		if (check_charset(str[i], charset) == 0 && \
				str[i + 1] == '\0')
			count = count + 1;
		i++;
	}
	return (count);
}

char **write_tab(char **tab, char *str, char *charset)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = 0;
	k = 1;
	tab[0][0] = str[0];
	while (str[i] != '\0')
	{
		if (check_charset(str[i], charset) == 0 && \
				check_charset(str[i - 1], charset) == 0)
			tab[j][k++] = str[i];
		if (check_charset(str[i - 1], charset) == 1 && \
				check_charset(str[i], charset) == 0)
		{
			j++;
			k = 0;
		}
		i++;
	}
	tab[j] = 0;
	return (tab);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		word;

	word = count_word(str, charset);
	tab = (char **)malloc(sizeof(char *) * (word + 1));
	if (tab == NULL)
		return (NULL);
	tab = write_tab(tab, str, charset);
	return (tab);
}
