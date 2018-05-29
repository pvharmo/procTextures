CC=g++
EXEC=tex
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

tex: main.o shapes.o
	$(CC) -o $(EXEC) main.o shapes.o $(LDFLAGS)

main.o: main.cpp
	$(CC) -o main.o -c main.cpp -W -Wall -ansi -pedantic
	
shapes.o: shapes.cpp shapes.h
	$(CC) -o shapes.o -c shapes.cpp -W -Wall -ansi -pedantic
	
	
.PHONY: clean mrproper	

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)