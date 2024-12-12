#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
int x1, y1, x2, y2,dx,dy,steps;
int gd= DETECT, gm;
initgraph( &gd,&gm,(char*)"");
cout << "\n Enter X1,Y1,X2,Y2";
cin >> x1 >> y1 >> x2 >> y2;
 
  dx = x2 - x1;
  dy = y2 - y1;
    if (dx >= dy)
    steps = dx;
  else
    steps = dy;
  dx = dx / steps;
  dy = dy / steps;
  int sx;
  if (dx >= 0)
    sx = 1;
  else
    sx = -1;
  int sy;
  if (dy >= 0)
    sy = 1;
  else
    sy = -1;
  float x = x1 + 0.5 * (sx);
  float y = y1 + 0.5 * (sy);
  int i = 0;
  while (i <= steps) {
    putpixel(int(x), int(y), 15);
    x = x + dx;
    y = y + dy;
    i = i + 1;
  }
 
  /* clean up */
  getch();
  closegraph();
  return 0;
}

