NAME = philo
CC = cc
SRC = main.c dinner_init.c util/atoi.c \
		util/strlen.c aux/is_valid_input.c \
		aux/init_args.c philo/set_forks.c \
		philo/set_philos.c aux/time.c \
		philo/destroy.c philo/simulation.c \
		philo/print_status.c philo/monitor_dies.c
	
SRC_PATH = $(addprefix ./src/, $(SRC))
C_FLGAS = -Wall -Werror -Wextra -pthread
HEADER = ./include/philo.h

all: $(NAME)

$(NAME): $(SRC_PATH) $(HEADER)
	$(CC) $(C_FLAGS) $(SRC_PATH) -o $(NAME)

clean:
fclean:
	rm -rf $(NAME)

re: fclean all