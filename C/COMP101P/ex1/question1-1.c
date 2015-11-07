// Written by Kelvin Chan, 07/10/2015.
// This program displays my name.

#include <stdio.h>
#include <string.h>

int main(void)
{
  char myName[] = "A Person";
  printf("Hello, my name is %s\n",myName);

  int index=strlen(myName)-1;
  while (index>-1)
    {
      printf("%c",myName[index]);
      index = index - 1;
    }
  printf("\n");
  return 0;
}
