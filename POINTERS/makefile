
CC = clang
#CFLAGS = -Wall -L/usr/local/opt/openssl@3/lib -L/usr/lib -lssl -lcrypto
CFLAGS = -Wall  -L/usr/lib

all:
		$(CC) $(CFLAGS) pointerIntro.c -o pointerIntro
exec:
		./pointerIntro
clean:
		rm -rf structuresIntro

pointerIntro:
		@$(CC) $(CFLAGS) pointerIntro.c -o pointerIntro
		@echo "\n----------------------------------------------------------------------------------\n"
		@echo "Running Program..." 
		@./PointerIntro

dynamicMemory:
		@$(CC) $(CFLAGS) dynamicMemory.c -o dynamicMemory
		@echo "\n----------------------------------------------------------------------------------\n"
		@echo "Running Program..." 
		@./dynamicMemory

countCharInString:
		@$(CC) $(CFLAGS) countCharInString.c -o countCharInString
		@echo "\n----------------------------------------------------------------------------------\n"
		@echo "Running Program..." 
		@./countCharInString
		@rm -rf countCharInString
		