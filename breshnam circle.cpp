#include<iostream>
#include<stdlib.h>
#include<graphics.h>
void circ_bre(int x,int y,int rad);
void display(int,int,int,int);
using namespace std;
int main()
{
    int gd = DETECT, gm, x,y,r;
    initgraph(&gd,&gm,(char*)"");
    cleardevice();
    cout<<"\nEnter the center co-ordinates for circle ";
    cin>>x>>y;
    cout<<"\nEnter the radius of the circle";
    cin>>r;
    circ_bre(x,y,r);
    getch();
    closegraph();
    return 0;
}
void circ_bre(int x,int y,int rad)
{
    float dp;       
    int x1,y1;
    x1 = 0;         
    y1 = rad;
    dp = 3 - 2*rad;
    while(x1<=y1)
    {
        if(dp<=0)
            dp += (4 * x1) + 6;
        else
        {
            dp += 4*(x1-y1)+10;
            y1--;
        }
        x1++;
        display(x1,y1,x,y);
    }
}
void display (int x1,int y1,int x,int y)
{
    putpixel(x1+x,y1+y,WHITE);  
    putpixel(x1+x,y-y1,WHITE);
    putpixel(x-x1,y1+y,WHITE);
    putpixel(x-x1,y-y1,WHITE);
    putpixel(x+y1,y+x1,WHITE);
    putpixel(x+y1,y-x1,WHITE);
    putpixel(x-y1,y+x1,WHITE);
    putpixel(x-y1,y-x1,WHITE);
}

