CC = g++ -std=c++11
EXE_FILE = permitMaker.out

&(EXE_FILE) : main.o general.o permit.o form.o interface.o
	$(CC) main.o  general.o permit.o form.o interface.o -o $(EXE_FILE)

main.o: interface.hpp general.hpp form.hpp permit.hpp main.cpp
	$(CC) -c main.cpp -o main.o


permit.o: permit.hpp general.hpp form.hpp permit.cpp
	$(CC) -c permit.cpp -o permit.o


general.o: general.hpp form.hpp permit.hpp general.cpp
	$(CC) -c general.cpp -o general.o


form.o: form.hpp general.hpp permit.hpp form.cpp
	$(CC) -c form.cpp -o form.o


interface.o: interface.hpp general.hpp form.hpp permit.hpp interface.cpp
	$(CC) -c interface.cpp -o interface.o


clean:
	rm *.o $(EXE_FILE)
