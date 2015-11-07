#include "graphics.h"
#include <math.h>
#include <stdio.h>

int main(void)
{
  /*  double angle = 128.571; */
  /*   double halfAngle = angle / 2; */
  /*   // double sin(double x); */
  /* double a = sin(64); */
  /*   double h = 10 /a; */

  //The centre of my heptgagon will be (100,100). The radius will be 30
  //Hence, the uppermost corner will be (100,130). 

  //To calculate the length of each edge, I will

  //Let the top point be 250,10 and length of edge to be 20

  double h = 20;
  double angle = 128.571;
  double halfAngle = angle / 2;
  double o = sin(halfAngle) * h;
  double a = sqrt(pow(h,2) - pow(o,2));

  printf("%f\n",a);

  drawLine(250,10,250+a,10+o);
  drawLine(250,10,250-a,10+o);

  // Assuming a length of 10 for the edge of the heptagon
  // sin(halfAngle) = 10 / H. So H = 10 / sin(halfAngle).
  /* printf("%f\n",h); */
  //top point
 
  return 0;
}


