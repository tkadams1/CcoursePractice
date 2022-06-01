
CC = clang
#CFLAGS = -Wall -L/usr/local/opt/openssl@3/lib -L/usr/lib -lssl -lcrypto
CFLAGS = -Wall  -L/usr/lib

all:
		$(CC) $(CFLAGS) tictactoe.c -o tictactoe
exec:
		./tictactoe
clean:
		rm -rf tictactoe

test:
		@$(CC) $(CFLAGS) tictactoe.c -o tictactoe
		@echo "\nRunning Program...\n" 
		@./tictactoe