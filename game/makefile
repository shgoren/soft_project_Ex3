CC = gcc
OBJS = solver_test.o solver.o
EXEC = solver_test
COMP_FLAG = -ansi -Wall -Wextra \
-Werror -pedantic-errors

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@
	
solver_test.o: solver.h solver_test.c
	$(CC) $(COMP_FLAG) -c $*.c
	
solver.o: solver.c solver.h game.h game.c
	$(CC) $(COMP_FLAG) -c $*.c
	
clean:
	rm -f $(OBJS) $(EXEC)
	