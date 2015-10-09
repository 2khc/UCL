#include <math.h>
#include <stdio.h>
#include "graphics.h"

int main(void)
{
  double i;
  double x;
  double y;
  int index = 0;
  for (i = -3*M_PI; i < 3*M_PI; i += 0.1)
    {
      y = sin(i)*100 + 100;
     x = (i*20)+3*M_PI*20;
     drawLine(x,y,x,y);
    }
}
