NAME = philo
CC = cc
SRC = main.c util/atoi.c
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