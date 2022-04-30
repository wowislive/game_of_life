/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include "main.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: count_neighbour_cell
 DESCRIPTION: returns the count of alive neighbours
	Input: int h, int w, struct cell b[BOARD_H][BOARD_W]
	Output: int count
  Used global variables: BOARD_H, BOARD_W
 REMARKS when using this function:
*********************************************************************/
int count_neighbour_cell(int h, int w, struct cell b[BOARD_H][BOARD_W]){

  int count = 0;
  int i,j;

  for(i=h-1; i<=h+1; i++){
    for(j=w-1; j<=w+1; j++){

      if(i==h && j==w)
        continue;
      
      if((i<BOARD_H) && (j<BOARD_W) && (i>=0) && (j>=0))
        count += b[i][j].current;
    }
  }
  
  return count;
}
