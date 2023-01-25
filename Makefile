CC      	= cc 
CFLAGS		= -Wall -Werror -Wextra
RM		= rm -rf

LIBFT		= ./libft/libft.a

UTILS		= src/utils.c
O_UTILS		= $(UTILS:.c=.o)

SERVER		= server

SERVER_SRC    	= src/server.c  
SERVER_OBJ	= $(SERVER_SRC:.c=.o)

CLIENT		= client

CLIENT_SRC	= src/client.c
CLIENT_OBJ	= $(CLIENT_SRC:.c=.o)

SERVER_B	= server_bonus

S_SRC_B		= src/server_bonus.c
S_OBJ_B  	= $(S_SRCB:.c=.o)

CLIENT_B	= client_bonus

C_SRC_B		= src/client_bonus.c
C_OBJ_B  	= $(C_SRCB:.c=.o)

all: $(SERVER) $(CLIENT)

$(LIBFT):
	$(MAKE) -C ./libft

LIBFT   	= libft/libft.a

all: $(SERVER) $(CLIENT)

bonus: $(SERVER_B) $(CLIENT_B)

$(SERVER): $(SERVER_OBJ) $(LIBFT) 
	$(CC) $(CFLAGS) $(SERVER_SRC) $(UTILS) $(LIBFT) -o server

$(CLIENT): $(CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_SRC) $(UTILS) $(LIBFT) -o client

$(SERVER_B): $(S_OBJ_B)$(LIBFT) 
	$(CC) $(CFLAGS) $(S_SRC_B) $(UTILS) $(LIBFT) -o server_bonus

$(CLIENT_B): $(C_OBJ_B) $(LIBFT) 
	$(CC) $(CFLAGS) $(C_SRC_B) $(UTILS) $(LIBFT) -o client_bonus

clean: 
	$(MAKE) clean -C ./libft
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(S_OBJ_B) $(C_OBJ_B)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(SERVER) $(CLIENT) $(SERVER_B) $(CLIENT_B)

re:	fclean all
