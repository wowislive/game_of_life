#include "main.h"

char ask_command(char c[]){  /*Ask char from user*/

  char s[MAX_USER_INPUT];
  do{
    printw(c);
    getstr(s);

    if(s[0] > 96 && s[0] < 123)
      s[0] -= 32;
  }while(s[0] < 65 && s[0] > 90);
  return s[0];
}
