S_TARGET = server
C_TARGET = client

CC		= cc
FLAGS	= -Wall -Wextra -Werror

INC = -I . -I ./libft -I ./ft_printf

LIBFT_DIR = ./libft
LIBFT	= $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

S_SRCS	= server.c
C_SRCS = client.c

S_OBJS	= $(S_SRCS:.c=.o)
C_OBJS = $(C_SRCS:.c=.o)

RM		= rm -f

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(C_TARGET) $(S_TARGET)

$(C_TARGET): $(C_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(FLAGS) -o $@ $(C_OBJS) $(INC) $(LIBFT) $(PRINTF)

$(S_TARGET): $(S_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(FLAGS) -o $@ $(S_OBJS) $(INC) $(LIBFT) $(PRINTF)

$(C_OBJS) $(S_OBJS): %.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ $(INC)

$(LIBFT) :
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

clean:
	make fclean -C libft
	make fclean -C ft_printf
	$(RM) $(S_OBJS) $(C_OBJS)

fclean:	clean
	$(RM) $(S_TARGET) $(C_TARGET)

re:	fclean	all

.PHONY:	all clean fclean re