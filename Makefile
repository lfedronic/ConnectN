connectn.out : board.o checkwin.o inputvalidation.o play.o connectn.o
	gcc -g -Wall -Werror -o connectn.out board.o checkwin.o inputvalidation.o play.o connectn.o
play.o : play.c board.h checkwin.h inputvalidation.h 
	gcc -g -Wall -Werror -c play.c
inputvalidation.o : inputvalidation.c board.h
	gcc -g -Wall -Werror -c inputvalidation.c
checkwin.o : checkwin.c
	gcc -g -Wall -Werror -c checkwin.c
board.o : board.c
	gcc -g -Wall -Werror -c board.c 
clean:
	rm -f *.o *.out 