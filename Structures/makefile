
CC = clang
#CFLAGS = -Wall -L/usr/local/opt/openssl@3/lib -L/usr/lib -lssl -lcrypto
CFLAGS = -Wall  -L/usr/lib

all:
		$(CC) $(CFLAGS) pointerIntro.c -o pointerIntro
exec:
		./pointerIntro
clean:
		rm -rf structuresIntro

test:
		@$(CC) $(CFLAGS) structuresIntro.c -o structuresIntro
		@echo "\n----------------------------------------------------------------------------------\n"
		@echo "Running Program..." 
		@./structuresIntro

dynamicMemory:
		@$(CC) $(CFLAGS) dynamicMemory.c -o dynamicMemory
		@echo "\n----------------------------------------------------------------------------------\n"
		@echo "Running Program..." 
		@./dynamicMemory
		