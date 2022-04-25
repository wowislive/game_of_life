gameoflife.exe: main.o init_board_state.o future_life_change.o count_neighbour_cell.o board_status_exchange.o ask_command.o main.h
	gcc main.o init_board_state.o future_life_change.o count_neighbour_cell.o board_status_exchange.o ask_command.o -o gameoflife

main.o:
	gcc -c -Wall -ansi -pedantic main.c

init_board_state.o:
	gcc -c -Wall -ansi -pedantic init_board_state.c

future_life_change.o:
	gcc -c -Wall -ansi -pedantic future_life_change.c

count_neighbour_cell.o:
	gcc -c -Wall -ansi -pedantic count_neighbour_cell.c

board_status_exchange.o:
	gcc -c -Wall -ansi -pedantic board_status_exchange.c

ask_command.o:
	gcc -c -Wall -ansi -pedantic ask_command.c

clean:
	del -f *.o *.exe