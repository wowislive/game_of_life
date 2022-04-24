#include "main.h"

char ask_command(void){  /*Ask char from user*/

  char s[MAX_USER_INPUT];

  do{
    fgets(s,MAX_USER_INPUT,stdin);

    if(s[0] > 96 && s[0] < 123)
      s[0] -= 32;
  }while(s[0] < 65 && s[0] > 90);
  return s[0];
}
