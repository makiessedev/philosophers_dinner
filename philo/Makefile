NAME = philo

SRC = main.c philo/init.c philo/threads.c \
		philo/monitor.c philo/routine_actions.c \
		aux/check_args.c aux/print_status.c \
		aux/destroy_all.c util/atoi.c util/strlen.c \
		util/get_current_time.c util/usleep.c

C_FILES = $(addprefix ./src/, $(SRC))

FLAGS = -Wall -Wextra -Werror -pthread -g

HEADER = ./include/philo.h

# SANITIZER = -fsanitize=thread


all: $(NAME)

$(NAME): $(C_FILES) $(HEADER)
	cc $(FLAGS) -o $(NAME) $(C_FILES) $(SANITIZER)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re