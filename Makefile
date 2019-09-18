CC      = gcc
RM      = rm -f

ass: assignment.c
	$(CC) -pthread -o ass assignment.c

clean veryclean:
	$(RM) ass
