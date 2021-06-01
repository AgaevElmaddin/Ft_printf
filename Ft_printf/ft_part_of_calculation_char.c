#include "ft_printf.h"

int		ft_calculation_of_char(t_parametrs *flag, char c)
{
	int count_symbols;

	count_symbols = 0;
	if (flag->minus == 1)
		ft_putchar(c);
	count_symbols += ft_print_width(flag->width, 1, 0);
	if (flag->minus == 0)
		ft_putchar(c);
	return (count_symbols + 1);
}

int		ft_calculation_of_percent(t_parametrs *flag)
{
	int	count_symbols;

	count_symbols = 0;
	if (flag->minus == 1)
		count_symbols += ft_putchar('%');
	count_symbols += ft_print_width(flag->width, 1, flag->zero);
	if (flag->minus == 0)
		count_symbols += ft_putchar('%');
	return (count_symbols);
}

int		ft_extra_str(t_parametrs *flag, char *s)
{
	int count_symbols;

	count_symbols = 0;
	if (flag->accurate >= 0)
	{
		count_symbols += ft_print_width(flag->accurate, ft_strlen(s), 0);
		count_symbols += ft_putstr(s, flag->accurate);
	}
	else
		count_symbols += ft_putstr(s, ft_strlen(s));
	return (count_symbols);
}

int		ft_calculation_of_str(t_parametrs *flag, char *s)
{
	int	count_symbols;

	count_symbols = 0;
	if (!s)
		s = "(null)";
	if (flag->accurate >= 0 && (size_t)flag->accurate > ft_strlen(s))
		flag->accurate = ft_strlen(s);
	if (flag->minus == 1)
		count_symbols += ft_extra_str(flag, s);
	if (flag->accurate >= 0)
		count_symbols += ft_print_width(flag->width, flag->accurate, 0);
	else
		count_symbols += ft_print_width(flag->width, ft_strlen(s), 0);
	if (flag->minus == 0)
		count_symbols += ft_extra_str(flag, s);
	return (count_symbols);
}
