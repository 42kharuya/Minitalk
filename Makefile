S_TARGET = server
C_TARGET = client

CC		= cc
FLAGS	= -Wall -Wextra -Werror

INC = -I . -I ./libft -I ./ft_printf

LIBFT_DIR = ./libft
LIBFT	= $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

ifdef WITH_BONUS
    S_SRCS = server_bonus.c
    C_SRCS = client_bonus.c
    S_OBJS = $(S_SRCS:.c=.o)
    C_OBJS = $(C_SRCS:.c=.o)
else
    S_SRCS = server.c
    C_SRCS = client.c
    S_OBJS = $(S_SRCS:.c=.o)
    C_OBJS = $(C_SRCS:.c=.o)
endif

UTILS_SRCS = utils.c
UTILS_OBJS = $(UTILS_SRCS:.c=.o)

RM		= rm -f

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(C_TARGET) $(S_TARGET)

$(C_TARGET): $(C_OBJS) $(UTILS_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(FLAGS) $(C_OBJS) $(UTILS_OBJS) $(LIBFT) $(PRINTF) -o $(C_TARGET)

$(S_TARGET): $(S_OBJS) $(UTILS_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(FLAGS) $(S_OBJS) $(UTILS_OBJS) $(LIBFT) $(PRINTF) -o $(S_TARGET)

$(C_OBJS) $(S_OBJS) $(UTILS_OBJS): %.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ $(INC)

$(LIBFT) :
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

bonus:
	make WITH_BONUS=1

clean:
	make fclean -C libft
	make fclean -C ft_printf
	$(RM) client.o server.o client_bonus.o server_bonus.o utils.o

fclean:	clean
	$(RM) $(S_TARGET) $(C_TARGET)

re:	fclean	all

.PHONY:	all clean fclean re bonus