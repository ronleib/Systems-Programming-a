
all: myBank.o main.o myBanks myBankd mains maind  

myBank.o: myBank.c myBank.h 
	gcc -Wall -g -fPIC -c myBank.c
main.o: main.c myBank.h 
	gcc -Wall -g -c main.c
maind: myBankd main.o
	gcc -Wall -g -o maind main.o ./libmyBank.so
mains: myBanks main.o 
	gcc -Wall -g -o mains main.o libmyBank.a
myBanks: myBank.o myBank.o
	ar -rcs libmyBank.a myBank.o
myBankd: myBank.o myBank.o 
	gcc -shared -o libmyBank.so myBank.o

.PHONY: clean all

clean:
	rm *.o *.a *.so mains maind
