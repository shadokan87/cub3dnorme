SRCS                    =       cub3d.c parts/splited1.c  parts/splited12.c parts/splited15.c parts/splited4.c  parts/splited7.c \
                                parts/splited0.c  parts/splited10.c parts/splited13.c parts/splited2.c  parts/splited5.c \
                                parts/splited8.c parts/splited11.c parts/splited14.c parts/splited3.c  parts/splited6.c \
                                parts/splited9.c parts/splited16.c\
                                ft_fprintf/arg_putchar.c ft_fprintf/arg_puthexa.c ft_fprintf/arg_putnbr.c ft_fprintf/arg_putptr.c ft_fprintf/arg_putstr.c ft_fprintf/arg_putunsigned.c ft_fprintf/c_str.c \
                                ft_fprintf/contain_num.c ft_fprintf/fill_precision.c ft_fprintf/fill_struct.c ft_fprintf/fill_width.c ft_fprintf/fill_width_type.c ft_fprintf/ft_atoi.c ft_fprintf/ft_isprint.c \
                                ft_fprintf/ft_memsub.c ft_fprintf/ft_nbrlen.c ft_fprintf/ft_nbrlen_u.c ft_fprintf/ft_printf.c ft_fprintf/ft_ptrlen.c ft_fprintf/ft_putchar.c ft_fprintf/ft_putchar_str.c \
                                ft_fprintf/ft_putnbr.c ft_fprintf/ft_putnbr_base.c ft_fprintf/ft_putnbr_base_u.c ft_fprintf/ft_putptr.c ft_fprintf/ft_putstr.c ft_fprintf/ft_realloc.c ft_fprintf/ft_split.c \
                                ft_fprintf/ft_strdup.c ft_fprintf/ft_strjoin.c ft_fprintf/ft_strlen.c ft_fprintf/ft_strrev.c ft_fprintf/get_next_arg.c ft_fprintf/get_width.c ft_fprintf/hidden_of.c ft_fprintf/hidden_strlen.c \
                                ft_fprintf/is_arg.c ft_fprintf/is_hidden.c ft_fprintf/is_num.c ft_fprintf/print_struct.c ft_fprintf/print_value_d.c ft_fprintf/print_value_u.c ft_fprintf/reset_struct.c \
                                ft_fprintf/write_const.c ft_fprintf/write_precision.c ft_fprintf/write_width.c \
                                gnl_working/get_next_line.c gnl_working/get_next_line_utils.c \

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -O3 -I ./ -g -Wall -Wextra -Werror
LIBS			= -framework OpenGL -framework AppKit -L ./ -lmlx

NAME			= cub3D

all:			$(NAME)

$(NAME):		$(MLX) $(OBJS)
				gcc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME) $(MLX)

re:				fclean $(NAME)
