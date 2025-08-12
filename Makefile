NAME = pipex
CFLAGS = -Wall -Wextra -Werror
Cfiles = fn_cmd_exe.c fn_extract_envp.c fn_main_helpers.c \
	ft_split.c ft_strdup.c ft_strjoin.c \
	ft_strlcpy.c ft_strlen.c ft_strnstr.c \
	ft_strrchr.c main.c

OBJS = $(Cfiles:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c pipex.h
	cc $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
