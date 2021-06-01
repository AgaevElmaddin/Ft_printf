#include "ft_printf.h"

static	int		len_of_number(long number)
{
	int	i;

	i = 0;
	if (number < 0)
		i++;
	if (number == 0)
		return (i = 1);
	while (number != 0)
	{
		number = number / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*dst;
	int		i;
	int		sign;

	sign = 1;
	i = len_of_number(n);
	dst = (char *)malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	dst[i--] = '\0';
	if (n == 0)
		dst[0] = '0';
	if (n < 0)
	{
		dst[0] = '-';
		sign = -1;
	}
	while (n != 0)
	{
		dst[i] = sign * (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (dst);
}

char			*ft_itoa_unsigned(unsigned int n)
{
	char	*dst;
	int		i;
	int		sign;

	sign = 1;
	i = len_of_number(n);
	dst = (char *)malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	dst[i--] = '\0';
	if (n == 0)
		dst[0] = '0';
	if (n < 0)
	{
		dst[0] = '-';
		sign = -1;
	}
	while (n != 0)
	{
		dst[i] = sign * (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (dst);
}

int				ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return ('A' + c - 'a');
	else
		return (c);
}

char			*ft_str_toupper(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		str[index] = ft_toupper(str[index]);
		index++;
	}
	return (str);
}
