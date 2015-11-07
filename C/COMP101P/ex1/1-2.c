// Written by Kelvin Chan, 07/10/2015.
// This program displays my name.

#include <stdio.h>
#include <string.h>

int main(void)
{
  char name[] = "Dept. of Computer Science";
  char address1[] = "Malet Place Engineering Building";
  printf("%s\n", name);
  printf("%s\n", address1);

  int index = strlen(name) - 1;
  while (index>-1)
    {
      printf("%c",name[index]);
      index = index - 1;
    }
  printf("\n");

  index = strlen(address1) -1;
  while (index > -1)
    {
      printf("%c", address1[index]);
      index = index - 1;
    }
  printf("\n");
  return 0;
}
