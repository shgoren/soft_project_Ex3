CC = gcc
OBJS = parser_test.o parser.o
EXEC = parser_test
COMP_FLAG = -ansi -Wall -Wextra \
-Werror -pedantic-errors

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@
	
parser_test.o: parser.h parser_test.c
	$(CC) $(COMP_FLAG) -c $*.c
	
parser.o: parser.c parser.h
	$(CC) $(COMP_FLAG) -c $*.c
	
clean:
	rm -f $(OBJS) $(EXEC)
