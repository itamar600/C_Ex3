CC=gcc
OBJECTS_MAIN_ISORT=mains.o sort.o
OBJECTS_MAIN_TXTFIND=main.o txt_find.o
FLAGS= -Wall -g

all: isort txtfind 	
isort: $(OBJECTS_MAIN_ISORT) 
	$(CC) $(FLAGS) -o  isort $(OBJECTS_MAIN_ISORT) 
txtfind: $(OBJECTS_MAIN_TXTFIND) 
	$(CC) $(FLAGS) -o  txtfind $(OBJECTS_MAIN_TXTFIND)	
sort.o: sort.c sort.h 
	$(CC) $(FLAGS) -fPIC -c sort.c
main.o: main.c txt_find.h   
	$(CC) $(FLAGS) -fPIC -c main.c 
txt_find.o: txt_find.c txt_find.h 
	$(CC) $(FLAGS) -fPIC -c txt_find.c
mains.o: mains.c sort.h   
	$(CC) $(FLAGS) -fPIC -c mains.c 


.PHONY: clean all

clean:
	rm -f *.o  *.out isort txtfind 