#include "ft_printf.h"

t_parametrs		ft_def_of_width(t_parametrs flag, char symbol)
{
	if (flag.star == 1)
		flag.width = 0;
	flag.width = flag.width * 10 + (symbol - 48);
	return (flag);
}

int				ft_calculations(t_parametrs flag, va_list ap, int symbol)
{
	int count_symbols;

	count_symbols = 0;
	if (symbol == 'd' || symbol == 'i')
		count_symbols = ft_calculation_of_int(&flag, va_arg(ap, int));
	else if (symbol == 'c')
		count_symbols = ft_calculation_of_char(&flag, va_arg(ap, int));
	else if (symbol == 's')
		count_symbols = ft_calculation_of_str(&flag, va_arg(ap, char *));
	else if (symbol == 'u')
	{
		count_symbols += ft_calculation_of_unsigned(&flag,
		(unsigned long)va_arg(ap, unsigned long));
	}
	else if (symbol == 'x')
		count_symbols += ft_calculation_hex(&flag, va_arg(ap, unsigned int), 0);
	else if (symbol == 'X')
		count_symbols += ft_calculation_hex(&flag, va_arg(ap, unsigned int), 1);
	else if (symbol == 'p')
		count_symbols = ft_calculat_ptr(&flag, va_arg(ap, unsigned long long));
	else if (symbol == '%')
		count_symbols += ft_calculation_of_percent(&flag);
	return (count_symbols);
}
