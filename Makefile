gameoflife.exe: main.o init_board_state.o future_life_change.o count_neighbour_cell.o board_status_exchange.o ask_command.o main.h
	gcc main.o init_board_state.o future_life_change.o count_neighbour_cell.o board_status_exchange.o ask_command.o -o gameoflife

main.o:
	gcc -c main.c	

init_board_state.o:
	gcc -c init_board_state.c

future_life_change.o:
	gcc -c future_life_change.c

count_neighbour_cell.o:
	gcc -c count_neighbour_cell.c

board_status_exchange.o:
	gcc -c board_status_exchange.c

ask_command.o:
	gcc -c ask_command.c

clean:
	del -f *.o *.exe