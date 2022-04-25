#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_H 9  /* board height */
#define BOARD_W 9  /* board width */
#define MAX_USER_INPUT 2000

struct cell{
int current;  /* current situation, which is visible on screen */
int future;   /* temporary calculation area for next round */
};

extern struct cell board [BOARD_H] [BOARD_W];

int count_neighbour_cell(int x, int y, struct cell b[BOARD_H][BOARD_W]);
int future_life_change(int i, int k);
void board_status_exchange(void);
char ask_command(void);
void print_current_board(void);
void init_board_state(void);
