#compiler
CC=gcc
#loader
LD=gcc

#compile flags -O3 for optimization -Wall to have compiler give extra warnings
CFLAGS= -O3 -Wall -W

#set OBJ_rdigest equal to the object files that are needed
OBJ_rdigest = rdigest.o digest.o read_sequence.o

#rule for linking object files to make target rdigest
rdigest : $(OBJ_rdigest)
	$(LD) -o rdigest $(OBJ_rdigest)

#rule to make object file rdigest.o 
rdigest.o : rdigest.c
	$(CC) $(CFLAGS) -c rdigest.c -o rdigest.o

#rule to make object file digest.o
digest.o : digest.c
	$(CC) $(CFLAGS) -c digest.c -o digest.o

#rule to make object file read_sequence.o
read_sequence.o : read_sequence.c
	$(CC) $(CFLAGS) -c read_sequence.c -o read_sequence.o

#phony target clean: remove compiled files
clean:
	rm *.o
	rm rdigest
