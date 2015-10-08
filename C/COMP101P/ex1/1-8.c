#include "graphics.h"

int main(void)
{
  int i;
  for (i = 0; i < 10; i++)
    {
      drawOval(10*i,10*i,10+ 5*i,6+3*i);
    }
}
