# Makefile 
# Andrew Turpin
# March 2013

OBJ     = main.o stack.o frame.o partition.o quicksort.o mergesort.o
CC      = g++
EXE     = assn1
CFLAGS  = -Wall -g

assn1:   $(OBJ) Makefile
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ)

clean:
	rm -f $(OBJ) $(EXE)

clobber: clean
	rm -f $(EXE)

usage: $(EXE)
	./$(EXE) 

main.o: partition.h quicksort.h mergesort.h Makefile
partition.o: partition.h 
quicksort.o: quicksort.h stack.h partition.h
mergesort.o: mergesort.h stack.h frame.h
stack.o: stack.h 
frame.o: frame.h
