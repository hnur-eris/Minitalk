NAME = minitalk
SRCLIENT = client.c
OBJSCLIENT = $(SRCLIENT:.c=.o)

SRCSERVER = server.c
OBJSERVER= $(SRCSERVER:.c=.o)

B_SRCSERVER = bonus/server_bonus.c
B_OBJSERVER = $(B_SRCSERVER:.c=.o)

B_SRCSCLIENT = bonus/client_bonus.c
B_OBJCLIENT = $(B_SRCSCLIENT:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): server client

server: $(OBJSERVER)
	gcc -o server $(SRCSERVER) $(CFLAGS)

client: $(OBJSCLIENT)
	gcc -o client $(SRCLIENT) $(CFLAGS)

s_bonus: $(B_OBJSERVER)
	gcc -o bonus/server $(B_SRCSERVER) $(CFLAGS)

c_bonus: $(B_OBJCLIENT)
	gcc -o bonus/client $(B_SRCSCLIENT) $(CFLAGS)

bonus: s_bonus c_bonus

clean:
	rm -f $(OBJSERVER) $(OBJSCLIENT) $(B_OBJSERVER) $(B_OBJCLIENT)

fclean: clean
	rm -f server client s_bonus c_bonus

re: fclean all

.PHONY: all clean fclean re
