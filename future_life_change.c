/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include "main.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: future_life_change
 DESCRIPTION: changes the life status of a cell depending on the number of neighbors
	Input: int i, int k
	Output: int life_state
  Used global variables: none
 REMARKS when using this function:
*********************************************************************/
int future_life_change(int i, int k){

  int life_state = k;

  if(i>3 || i<2)
    life_state = 0;
  
  else if(i==3)
    life_state = 1;

  return life_state;
}
