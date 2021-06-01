#include "ft_printf.h"

int		ft_ptr_extra(t_parametrs *flag, char *ptr)
{
	int count_symbols;

	count_symbols = 0;
	count_symbols += ft_putstr("0x", 2);
	if (flag->accurate >= 0)
	{
		count_symbols += ft_print_width(flag->accurate, ft_strlen(ptr), 1);
		count_symbols += ft_putstr(ptr, ft_strlen(ptr));
	}
	else
		count_symbols += ft_putstr(ptr, ft_strlen(ptr));
	return (count_symbols);
}

int		ft_calculat_ptr(t_parametrs *flag, unsigned long long n)
{
	int		count_symbols;
	char	*ptr;

	count_symbols = 0;
	if (n == 0 && flag->accurate == 0)
	{
		count_symbols += ft_putstr("0x", 2);
		return (count_symbols += ft_print_width(flag->width, 0, 1));
	}
	if (!(ptr = ft_itoa_hex(n)))
		return (0);
	ptr = ft_str_tolower(ptr);
	if ((size_t)flag->accurate < ft_strlen(ptr))
		flag->accurate = ft_strlen(ptr);
	if (flag->minus == 1)
		count_symbols += ft_ptr_extra(flag, ptr);
	count_symbols += ft_print_width(flag->width, ft_strlen(ptr) + 2, 0);
	if (flag->minus == 0)
		count_symbols += ft_ptr_extra(flag, ptr);
	free(ptr);
	return (count_symbols);
}
