#include "ft_printf.h"

int		ft_extra_unsigned(t_parametrs *flag, char *result, unsigned int n)
{
	int		count_symbols;

	count_symbols = 0;
	n = (unsigned long)4294967295 + 1 + n;
	if (flag->accurate >= 0)
	{
		count_symbols += ft_print_width(flag->accurate - 1,
		ft_strlen(result) - 1, 1);
	}
	count_symbols += ft_putstr(result, ft_strlen(result));
	return (count_symbols);
}

int		ft_print_width_extra(t_parametrs *flag, char *result, unsigned int n)
{
	int		count_symbols;

	count_symbols = 0;
	n = (unsigned long)4294967295 + 1 + n;
	count_symbols += ft_print_width(flag->width, ft_strlen(result), flag->zero);
	return (count_symbols);
}

int		ft_dif_between_width_and_accurate(t_parametrs *flag, unsigned int n)
{
	int		count_symbols;

	count_symbols = 0;
	n = (unsigned long)4294967295 + 1 + n;
	flag->width -= flag->accurate;
	count_symbols += ft_print_width(flag->width, 0, 0);
	return (count_symbols);
}

int		ft_calculation_of_unsigned(t_parametrs *flag, unsigned int n)
{
	int		count_symbols;
	char	*result;

	count_symbols = 0;
	n = (unsigned long)4294967295 + 1 + n;
	result = ft_itoa_unsigned(n);
	if (flag->accurate == 0 && n == 0)
	{
		count_symbols += ft_print_width(flag->width, 0, 0);
		return (count_symbols);
	}
	if (flag->minus == 1)
		count_symbols += ft_extra_unsigned(flag, result, n);
	if (flag->accurate >= 0 && (size_t)flag->accurate < ft_strlen(result))
		flag->accurate = ft_strlen(result);
	if (flag->accurate >= 0)
		count_symbols += ft_dif_between_width_and_accurate(flag, n);
	else
		count_symbols += ft_print_width_extra(flag, result, n);
	if (flag->minus == 0)
		count_symbols += ft_extra_unsigned(flag, result, n);
	free(result);
	return (count_symbols);
}
