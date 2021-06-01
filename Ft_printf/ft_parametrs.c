#include "ft_printf.h"

int				ft_type(int symbol)
{
	return (symbol == 'd' || symbol == 'i' || symbol == 'c' || symbol == 's' ||
	symbol == 'x' || symbol == 'X' || symbol == 'p' || symbol == 'u' ||
	symbol == '%');
}

int				ft_flags(int symbol)
{
	return (symbol == '-' || symbol == '0' || symbol == '.' || symbol == '*');
}

t_parametrs		ft_existence_of_minus(t_parametrs flag)
{
	flag.minus = 1;
	flag.zero = 0;
	return (flag);
}

int				ft_existence_of_dot_and_star(const char *fmt, t_parametrs *flag,
				va_list ap, int current_position)
{
	int	index;

	index = current_position;
	index++;
	if (fmt[index] == '*')
	{
		flag->accurate = va_arg(ap, int);
		index++;
	}
	else
	{
		flag->accurate = 0;
		while (ft_isdigit(fmt[index]))
		{
			flag->accurate = (flag->accurate * 10) + (fmt[index] - 48);
			index++;
		}
	}
	return (index);
}

t_parametrs		ft_star_and_width(t_parametrs flag, va_list ap)
{
	flag.star = 1;
	flag.width = va_arg(ap, int);
	if (flag.width < 0)
	{
		flag.zero = 0;
		flag.minus = 1;
		flag.width *= -1;
	}
	return (flag);
}
