#include "ft_printf.h"

int		ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return ('a' + c - 'A');
	else
		return (c);
}

char	*ft_str_tolower(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		str[index] = ft_tolower(str[index]);
		index++;
	}
	return (str);
}
