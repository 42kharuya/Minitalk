#This is to execute with relink
NAME	= libft.a

LST		= ./lst
MEM		= ./mem
PUT		= ./put
STR		= ./str
TO		= ./to
IS		= ./is
SRCS	= $(IS)/ft_isalpha.c $(IS)/ft_isdigit.c $(IS)/ft_isalnum.c $(IS)/ft_isascii.c \
		$(IS)/ft_isprint.c $(STR)/ft_strlen.c $(MEM)/ft_memset.c ft_bzero.c \
		$(MEM)/ft_memcpy.c $(MEM)/ft_memmove.c $(STR)/ft_strlcpy.c $(STR)/ft_strlcat.c \
		$(TO)/ft_toupper.c $(TO)/ft_tolower.c $(STR)/ft_strchr.c $(STR)/ft_strrchr.c \
		$(STR)/ft_strncmp.c $(MEM)/ft_memchr.c $(MEM)/ft_memcmp.c $(STR)/ft_strnstr.c \
		ft_atoi.c ft_calloc.c $(STR)/ft_strdup.c ft_substr.c \
		$(STR)/ft_strjoin.c $(STR)/ft_strtrim.c ft_split.c ft_itoa.c \
		$(STR)/ft_strmapi.c $(STR)/ft_striteri.c $(PUT)/ft_putchar_fd.c \
		$(PUT)/ft_putstr_fd.c $(PUT)/ft_putendl_fd.c $(PUT)/ft_putnbr_fd.c
SRCS_BONUS	=	$(LST)/ft_lstnew.c $(LST)/ft_lstadd_front.c $(LST)/ft_lstsize.c \
				$(LST)/ft_lstlast.c $(LST)/ft_lstadd_back.c $(LST)/ft_lstdelone.c \
				$(LST)/ft_lstclear.c $(LST)/ft_lstiter.c $(LST)/ft_lstmap.c
OBJS	= $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS_BONUS)
	touch bonus
	ar rcs $(NAME) $(OBJS_BONUS)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS) bonus

fclean:	clean
	$(RM) $(NAME)

re:	fclean	all

.PHONY:	all clean fclean re