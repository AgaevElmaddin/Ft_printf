#include "ft_printf.h"
t_parametrs		ft_initialize_parametrs(t_parametrs flag)
{
	flag.star = 0;
	flag.minus = 0;
	flag.dot = 0;
	flag.accurate = -1;
	flag.zero = 0;
	flag.width = 0;
	flag.type = 0;
	return (flag);
}

int				ft_symbol_fmt(const char *fmt, t_parametrs *flag, va_list ap,
		int index)
{
	while (fmt[index])
	{
		if (!ft_isdigit(fmt[index]) && !ft_type(fmt[index]) &&
			!ft_flags(fmt[index]))
			break ;
		if (ft_isdigit(fmt[index]))
			*flag = ft_def_of_width(*flag, fmt[index]);
		if (fmt[index] == '-')
			*flag = ft_existence_of_minus(*flag);
		if (fmt[index] == '0' && flag->minus == 0 && flag->width == 0)
			flag->zero = 1;
		if (fmt[index] == '.')
			index = ft_existence_of_dot_and_star(fmt, flag, ap, index);
		if (fmt[index] == '*')
			*flag = ft_star_and_width(*flag, ap);
		if (ft_type(fmt[index]))
		{
			flag->type = fmt[index];
			break ;
		}
		index++;
	}
	return (index);
}

int				ft_get_fmt(const char *fmt, va_list ap)
{
	int			index;
	int			count_symbols;
	t_parametrs	flag;

	index = 0;
	count_symbols = 0;
	while (fmt[index])
	{
		flag = ft_initialize_parametrs(flag);
		if (!fmt[index])
			break ;
		else if (fmt[index] != '%')
			count_symbols += ft_putchar(fmt[index]);
		else if (fmt[index] == '%' && fmt[index + 1])
		{
			index = ft_symbol_fmt(fmt, &flag, ap, ++index);
			if (ft_type(fmt[index]))
				count_symbols += ft_calculations(flag, ap, (char)flag.type);
			else if (fmt[index])
				count_symbols += ft_putchar(fmt[index]);
		}
		index++;
	}
	return (count_symbols);
}

int				ft_printf(const char *fmt, ...)
{
	int		count_symbols;
	va_list ap;

	va_start(ap, fmt);
	count_symbols = 0;
	count_symbols = ft_get_fmt(fmt, ap);
	va_end(ap);
	return (count_symbols);
}
