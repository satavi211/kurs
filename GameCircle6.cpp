#include "TXLib.h"

//  »гра. Ѕольшой красный шарик управл€етс€ клавишами LEFT, RIGHT, UP, DOWN.
//  Ѕольшим красным шариком нужно ловить все остальные. при соприкосновении с ними, он мен€ет свой цвет

void   DrawCircle(double x,double y, int r, COLORREF color);
void   Motion();
void   phisics( double *x,double *y,double *vx,double *vy, COLORREF color, int r);
double Distance(double x1, double y1, double x2, double y2);
void Uprav(double *x,double *y,double *vx, double *vy, COLORREF color,int r);
void Fon();

int main ()
{
    txCreateWindow (800, 600);
    Motion();
    return 0;
}

void Motion()
{
        double x1=0,   y1=0,   dx1=5, dy1=2;
        double x2=800, y2=600, dx2=1, dy2=1;
        int    r1=20,  r2=50,  r3=30, r4=20;
        double x3=800, y3=0,   dx3=3, dy3=2;
        double x4=0,   y4=600, dx4=2, dy4=3;
        int    k=0;

    while (!txGetAsyncKeyState(VK_ESCAPE))
    {
        Fon();
        phisics(&x1, &y1, &dx1, &dy1, RGB(20,  20, 255),r1);
        phisics(&x2, &y2, &dx2, &dy2, RGB(200, 50, 10), r2);
        Uprav(&x2, &y2, &dx2, &dy2,   RGB(k+240,  k+30, k+10), r2);
        if (Distance(x1, y1, x2, y2)<=(r1+r2)*( r1+r2))
        {
            k+=5;
            k=k % 200;
        }
        phisics(&x3, &y3, &dx3, &dy3, RGB(10,  150,  200),r3);
        if (Distance(x3, y3, x2, y2)<=(r3+r2)*( r3+r2))
        {
            k+=5;
            k=k % 200;
        }
        phisics(&x4, &y4, &dx4, &dy4, RGB(200,  200, 10),r4);
        if (Distance(x4, y4, x2, y2)<=(r4+r2)*( r4+r2))
        {
            k+=5;
            k=k % 200;
        }
        txSleep(10);
        //txClear();
    }

}
void DrawCircle(double x,double y, int r, COLORREF color )
     {

     txSetFillColor (color);
     txCircle(x,y,r);
     }
void phisics( double *x,double *y,double *vx, double *vy, COLORREF color,int r)
{
        *x+=*vx;
        *y+=*vy;

        //txSetFillColor (color);
        DrawCircle(*x,*y, r, color);

        if (*y>600-r)
        {
            *y=600-r;
            *vy=-*vy;
        }
        if (*y<r)
        {
            *y=r;
            *vy=-*vy;
        }
        if (*x>800-r)
        {
            *x=800-r;
            *vx=-*vx;
        }
        if (*x<r)
        {
            *x=r;
            *vx=-*vx;
        }

}
double Distance(double x1, double y1, double x2, double y2)
{
    double dist=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    return dist;

}
void Uprav(double *x,double *y,double *vx, double *vy, COLORREF color,int r)
{
    if (txGetAsyncKeyState(VK_RIGHT) )
    {
        *x+=20;
    }
    if (txGetAsyncKeyState(VK_LEFT) )
    {
        *x-=20;
    }
    if (txGetAsyncKeyState(VK_UP) )
    {
        *y-=20;
    }
    if (txGetAsyncKeyState(VK_DOWN))
    {
        *y+=20;
    }
        //*x+=*vx;
        //*y+=*vy;

        txSetFillColor (color);
        DrawCircle(*x,*y,r, color);

        if (*y>600-r)
        {
            *y=600-r;
            *vy=-*vy;
        }
        if (*y<r)
        {
            *y=r;
            *vy=-*vy;
        }
        if (*x>800-r)
        {
            *x=800-r;
            *vx=-*vx;
        }
        if (*x<r)
        {
            *x=r;
            *vx=-*vx;
        }
}
void Fon()
{
    txSetColor     (TX_WHITE);
    txSetFillColor (TX_WHITE);
    txRectangle    (800, 0,  0, 600);
    txFloodFill    (765, 400);
}

