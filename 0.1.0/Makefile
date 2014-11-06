CC = gcc
CFLAGS = -g -march=native -Wall -O3 `pkg-config --cflags glib-2.0 gsl`
LIBS = -lm `pkg-config --libs glib-2.0 gsl`
DEP = makefile
OBJ = entity.o population.o reproduction.o selection.o evolution.o genetic.o

all: test_genetic

entity.o: entity.c entity.h $(DEP)
	$(CC) $(CFLAGS) -c entity.c -o entity.o

population.o: population.c population.h entity.h bits.h $(DEP)
	$(CC) $(CFLAGS) -c population.c -o population.o

reproduction.o: reproduction.c reproduction.h entity.h bits.h $(DEP)
	$(CC) $(CFLAGS) -c reproduction.c -o reproduction.o

selection.o: selection.c selection.h population.h entity.h $(DEP)
	$(CC) $(CFLAGS) -c selection.c -o selection.o

evolution.o: evolution.c evolution.h selection.h reproduction.h mutation.h \
	population.h entity.h sort.h bits.h $(DEP)
	$(CC) $(CFLAGS) -c evolution.c -o evolution.o

genetic.o: genetic.c genetic.h evolution.h selection.h reproduction.h \
	population.h entity.h bits.h $(DEP)
	$(CC) $(CFLAGS) -c genetic.c -o genetic.o

test_genetic: test_genetic.c $(OBJ)
	$(CC) $(CFLAGS) test_genetic.c $(OBJ) -o test_genetic $(LIBS)
