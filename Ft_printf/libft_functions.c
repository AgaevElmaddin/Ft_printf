#include "ft_printf.h"

int				ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int				ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

size_t			ft_strlen(const char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int				ft_putstr(char *s, int i)
{
	int		count_symbols;
	int		index;

	index = 0;
	count_symbols = 0;
	if (!s)
		return (0);
	while (index < i)
	{
		write(1, &s[index], 1);
		count_symbols++;
		index++;
	}
	return (count_symbols);
}

char			*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	dst = (char *)malloc(sizeof(char) * (i + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
