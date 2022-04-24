#include "main.h"

int future_life_change(int i, int k){  /*changes the life status of a cell depending on the number of neighbors*/

  int life_state = k;

  if(i>3 || i<2)
    life_state = 0;
  
  else if(i==3)
    life_state = 1;

  return life_state;
}
