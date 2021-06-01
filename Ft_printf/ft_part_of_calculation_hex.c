#include "ft_printf.h"

char	*ft_itoa_hex(unsigned long long n)
{
	unsigned long long	tmp;
	int					len_of_n;
	char				*mas;

	tmp = n;
	len_of_n = 1;
	if (n == 0)
		return (ft_strdup("0"));
	while (tmp /= 16)
		len_of_n++;
	if (!(mas = (char *)malloc(sizeof(char) * (len_of_n + 1))))
		return (NULL);
	mas[len_of_n] = '\0';
	while (n != 0)
	{
		if (n % 16 < 10)
			mas[len_of_n - 1] = n % 16 + 48;
		else
			mas[len_of_n - 1] = n % 16 + 87;
		n /= 16;
		len_of_n--;
	}
	return (mas);
}

int		ft_extra_hex(t_parametrs *flag, int upper, char *a)
{
	int		count_symbols;

	count_symbols = 0;
	if (upper == 1)
		a = ft_str_toupper(a);
	if (flag->accurate >= 0)
	{
		count_symbols += ft_print_width(flag->accurate - 1,
		ft_strlen(a) - 1, 1);
	}
	count_symbols += ft_putstr(a, ft_strlen(a));
	return (count_symbols);
}

int		ft_width_minus_accurate(t_parametrs *flag, int upper, char *a)
{
	int		count_symbols;

	count_symbols = 0;
	if (upper == 1)
		a = ft_str_toupper(a);
	flag->width -= flag->accurate;
	count_symbols += ft_print_width(flag->width, 0, 0);
	return (count_symbols);
}

int		ft_calculation_hex(t_parametrs *flag, unsigned int hex, int upper)
{
	int		count_symbols;
	char	*a;

	count_symbols = 0;
	a = ft_itoa_hex(hex);
	if (upper == 1)
		a = ft_str_toupper(a);
	if (flag->accurate == 0 && hex == 0)
	{
		count_symbols += ft_print_width(flag->width, 0, 0);
		free(a);
		return (count_symbols);
	}
	if (flag->minus == 1)
		count_symbols += ft_extra_hex(flag, upper, a);
	if (flag->accurate >= 0 && (size_t)flag->accurate < ft_strlen(a))
		flag->accurate = ft_strlen(a);
	if (flag->accurate >= 0)
		count_symbols += ft_width_minus_accurate(flag, upper, a);
	else
		count_symbols += ft_print_width(flag->width, ft_strlen(a), flag->zero);
	if (flag->minus == 0)
		count_symbols += ft_extra_hex(flag, upper, a);
	free(a);
	return (count_symbols);
}
