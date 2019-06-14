#include <stdlib.h>

int		is(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

int		count_world(char *t)
{
	int y;

	y = 0;
	if (t && *t)
	{
		if (!is(*t))
			y++;
		while (*t)
			if (is(*t++) && *t && !is(*t))
				y++;
	}
	return (y);
}


int		count_char(char *str)
{
	int i;

	i = 0;
	if (str && str[i])
		while (str[i] && !is(str[i]))
			i++;
	return (i);
}

char	*ft_make(char *str)
{
	char	*t;
	int		i;
	int		b;

	t = NULL;
	i = count_char(str);
	if (!(t = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	b = 0;
	if (str)
		while (str[b] && !is(str[b]))
		{
			t[b] = str[b]; 
			b++;
		}
	t[b] = '\0';
	return (t);
}

char	**ft_split(char *str)
{
	char	**b;
	int		i;
	int		c;

	i = count_world(str);
	if (!(b = (char **)malloc(sizeof(char *) * i + 1)))
		return (NULL);
	c = 0;
	if (str)
		while (c < i)
		{
			while (*str && is(*str))
				str++;
			if (*str)
				b[c] = ft_make(str);
			while (*str && !is(*str))
				str++;
			c++;
		}
	b[c] = NULL;
	return (b);
}
