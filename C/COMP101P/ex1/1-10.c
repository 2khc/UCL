#include "graphics.h"
#include <stdio.h>

int main(void)
{
  int barWidth, lineLength, interval, i,
    startX, startY, originX, originY, horizLabelsY;

  char buffer[5];
  char* str;
  barWidth = 50;
  interval = 50;
  lineLength = interval * 4;
  startX = 30;
  startY = 30;
  originX = 30;
  originY = 30 + lineLength;
  horizLabelsY = originY + 20;

  drawLine(30,30,30,30+lineLength);
  drawLine(30,30+lineLength,30+barWidth+lineLength,30+lineLength);
  
  for (i = 0; i < 4; i++)
    /* sprintf(str,"%d",i); */
      {
	drawLine(startX,startY+interval+interval*i, 27,startY+interval+interval*i);
	/* drawString(str,originX-10,startY+interval+interval*i); */
      }

  setColour(blue);
  fillRect(originX, originY-65,barWidth,65);
  setColour(green);
  fillRect(originX+barWidth,originY-140,barWidth,140);
  setColour(red);
  fillRect(originX+barWidth*2,originY-120,barWidth,120);
  setColour(yellow);
  fillRect(originX+barWidth*3,originY-87,barWidth,87);
  setColour(pink);
  fillRect(originX+barWidth*4,originY-137,barWidth,137);

  //x axis words
  setColour(black);
  drawString("CDs",originX,horizLabelsY);
  drawString("DVDs",originX+barWidth,horizLabelsY);
  drawString("BookS",originX+barWidth*2,horizLabelsY);
  drawString("Clothes",originX+barWidth*3,horizLabelsY);
  drawString("Shoes",originX+barWidth*4,horizLabelsY);

  //y labels
  drawString("50",originX - 30,originY-interval);
  drawString("100",originX-30,originY-interval*2);
  drawString("150",originX-30,originY-interval*3);
  
}
