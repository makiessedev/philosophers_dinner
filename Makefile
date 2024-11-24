NAME = philo

SRC = main.c util/utils.c philo/init.c philo/threads.c \
		philo/monitor.c philo/routine_actions.c \
		aux/check_args.c aux/print_status.c

C_FILES = $(addprefix ./src/, $(SRC))

FLAGS = -Wall -Wextra -Werror -pthread

HEADER = ./include/philo.h

#SANITIZER = -fsanitize=thread


all: $(NAME)

$(NAME): $(C_FILES) $(HEADER)
	cc $(FLAGS) -o $(NAME) $(C_FILES) $(SANITIZER)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re