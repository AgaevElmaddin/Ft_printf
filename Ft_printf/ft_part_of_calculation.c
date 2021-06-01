#include "ft_printf.h"

int		ft_print_width(int width, int len_of_type, int dependence)
{
	int		count_symbols;

	count_symbols = 0;
	while (width > len_of_type)
	{
		if (dependence == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width--;
		count_symbols++;
	}
	return (count_symbols);
}

int		ft_extra_int(t_parametrs *flag, char *result)
{
	int		count_symbols;

	count_symbols = 0;
	if (flag->accurate >= 0)
		count_symbols += ft_print_width(flag->accurate - 1,
						ft_strlen(result) - 1, 1);
	count_symbols += ft_putstr(result, ft_strlen(result));
	return (count_symbols);
}

int		ft_connection_b_width_and_accurate(t_parametrs *flag)
{
	int		count_symbols;

	count_symbols = 0;
	flag->width -= flag->accurate;
	count_symbols += ft_print_width(flag->width, 0, 0);
	return (count_symbols);
}

int		ft_extra_calculation_d(t_parametrs *flag, int tmp, char *result, int d)
{
	int		count_symbols;

	count_symbols = 0;
	if (flag->minus == 1)
	{
		if (flag->accurate >= 0 && tmp < 0 && d != -2147483648)
			ft_putchar('-');
		count_symbols += ft_extra_int(flag, result);
	}
	if (flag->accurate >= 0 && (size_t)flag->accurate < ft_strlen(result))
		flag->accurate = ft_strlen(result);
	if (flag->accurate >= 0)
		count_symbols += ft_connection_b_width_and_accurate(flag);
	else
		count_symbols += ft_print_width(flag->width, ft_strlen(result),
										flag->zero);
	if (flag->minus == 0)
	{
		if (flag->accurate >= 0 && tmp < 0 && d != -2147483648)
			ft_putchar('-');
		count_symbols += ft_extra_int(flag, result);
	}
	return (count_symbols);
}

int		ft_calculation_of_int(t_parametrs *flag, int d)
{
	int		count_symbols;
	char	*result;
	int		tmp;

	count_symbols = 0;
	tmp = d;
	if (flag->accurate == 0 && d == 0)
	{
		count_symbols += ft_print_width(flag->width, 0, 0);
		return (count_symbols);
	}
	if (d < 0 && (flag->zero == 1 || flag->accurate >= 0) && d != -2147483648)
	{
		if (flag->accurate <= -1 && flag->zero == 1)
			ft_putstr("-", 1);
		d *= -1;
		flag->zero = 1;
		flag->width--;
		count_symbols++;
	}
	result = ft_itoa(d);
	count_symbols += ft_extra_calculation_d(flag, tmp, result, d);
	free(result);
	return (count_symbols);
}
