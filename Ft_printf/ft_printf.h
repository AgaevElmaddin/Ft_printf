#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct		s_parametrs_of_format
{
	int				accurate;
	int				width;
	int				star;
	int				dot;
	int				zero;
	int				minus;
	char			type;
}					t_parametrs;

char				*ft_itoa_unsigned(unsigned int n);
char				*ft_itoa_hex(unsigned long long n);
char				*ft_str_tolower(char *str);
int					ft_tolower(int c);
int					ft_calculat_ptr(t_parametrs *flag, unsigned long long n);
char				*ft_str_toupper(char *str);
int					ft_toupper(int c);
char				*ft_strdup(const char *s1);
int					ft_calculation_of_unsigned(t_parametrs *flag,
					unsigned int n);
int					ft_calculation_hex(t_parametrs *flag, unsigned int hex,
					int upper);
int					ft_calculation_of_str(t_parametrs *flag, char *s);
int					ft_calculation_of_percent(t_parametrs *flag);
int					ft_calculation_of_char(t_parametrs *flag, char c);
int					ft_print_width(int width, int len_of_type, int dependence);
int					ft_putstr(char *s, int i);
int					ft_calculation_of_int(t_parametrs *flag, int d);
int					ft_printf(const char *fmt, ...);
int					ft_putchar(char c);
int					ft_isdigit(int c);
size_t				ft_strlen(const char *str);
char				*ft_strrchr(const char *s, int c);
int					ft_type(int symbol);
int					ft_flags(int symbol);
t_parametrs			ft_existence_of_minus(t_parametrs flag);
int					ft_existence_of_dot_and_star(const char *fmt,
					t_parametrs *flag, va_list ap, int current_position);
t_parametrs			ft_star_and_width(t_parametrs flag, va_list ap);
t_parametrs			ft_def_of_width(t_parametrs flag, char symbol);
int					ft_calculations(t_parametrs flag, va_list ap, int symbol);
char				*ft_itoa(int n);

#endif
