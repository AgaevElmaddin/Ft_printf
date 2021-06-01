NAME = libftprintf.a

SRCS = ft_calculations.c ft_parametrs.c ft_part_of_calculation_char.c\
		ft_part_of_calculation_hex.c ft_part_of_calculation_ptr.c\
		ft_part_of_calculation_unsigned.c ft_part_of_calculation.c\
		ft_printf.c libft_functions_2.c libft_functions_3.c\
		libft_functions.c

OBJS = ft_calculations.o ft_parametrs.o ft_part_of_calculation_char.o\
		ft_part_of_calculation_hex.o ft_part_of_calculation_ptr.o\
		ft_part_of_calculation_unsigned.o ft_part_of_calculation.o\
		ft_printf.o libft_functions_2.o libft_functions_3.o\
		libft_functions.o

HEADER = ft_printf.h

CC = gcc

RM = rm -f

FLAGS = -Wall -Werror -Wextra

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs  $(NAME) $(OBJS)

$(OBJS): $(SRCS) $(HEADER)
	$(CC) $(FLAGS) -c $(SRCS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: all, clean, fclean, re
