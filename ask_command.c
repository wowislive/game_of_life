/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include "main.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: ask_command
 DESCRIPTION: Ask char from user
	Input: char c[]
	Output: char s[0]
  Used global variables: none
 REMARKS when using this function:
*********************************************************************/
char ask_command(char c[]){

  char s[MAX_USER_INPUT];
  do{
    printw(c);
    getstr(s);

    if(s[0] > 96 && s[0] < 123)
      s[0] -= 32;
  }while(s[0] < 65 && s[0] > 90);
  return s[0];
}
