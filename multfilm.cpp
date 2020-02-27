#include "TXLib.h"

void DrawSky (COLORREF Color);
void DrawTree (double x, double y, double up,double angle);
void DrawSun (double x,double y,COLORREF Color)  ;
void DrawBird (double x, double y, double up, double angle) ;
void GoodMorning();
void GoodEvening();
void Titr();

int main()
    {
    txCreateWindow (800, 600);
    GoodMorning();
    txSleep(500);
    txClear();
    GoodEvening ();
    txSleep(500);
    Titr();
    return 0;
    }

void GoodMorning()
    {
    int t=0;
    while (t<650)
    {
        txSleep(100);
        txClear();


        txSetColor     (TX_WHITE);
        txSetFillColor (TX_WHITE);
        txRectangle    (800, 0,  0, 600);
        txFloodFill    (765, 400);

        txSetFillColor (TX_YELLOW);
        txFloodFill    (765, 400);

        DrawTree(5,   100, 1, abs(t % 7)*15);

        DrawTree(350, 150, 2, abs(t % 4)*5-5);

        DrawTree(500, 400, 4,abs(t % 3)*5-5);

        DrawSun (0,0,RGB(200,200,0)) ;

        DrawSky (RGB(0+t %200,0,255));
        DrawSun (0,0,RGB(100+t,100+t,0));

        DrawBird (300-t,300-t,2, abs(t%4)*10-5);
        DrawBird (400-t*2,200-t,3, abs(t%4)*20-2);

        t=t+10;

    }


    txSetColor (TX_PINK,10);
    txTextOut (300, 10, "GOOD MORNING");

    }
void GoodEvening ()
{
    int t=0;
    while (t<100)
    {
        txSleep(100);
        txClear();


        txSetColor     (RGB(10,10,10));
        txSetFillColor (RGB(100,100,100));
        txRectangle    (800, 0,  0, 600);
        txFloodFill    (765, 400);

        txSetFillColor (RGB(100,100,100));
        txFloodFill    (765, 400);

        DrawTree(5,100,1,abs(t % 7)*5);

        DrawTree(350,150,2,abs(t % 3)*2-5);

        DrawTree(500,400,4,abs(t % 2)*2-5);


        DrawBird (500-t,100+t,2, abs(t%4)*10-5);
        DrawBird (400-t*2,200+t,3, abs(t%4)*20-2);
        DrawSun (0+t,0+t,RGB(200,200,0)) ;

        t=t+1;
        DrawSky (RGB(t %200,t %200,255));


    }
        txClear();

        DrawSky (RGB(10, 10, 255));
        DrawSun (0+t,0+t,RGB(10,10,255));

        txSetColor (TX_WHITE,10);
        txTextOut (300, 10, "Good Evening");
        txSetFillColor (RGB(50, 50, 100));
        txRectangle (0, 250, 800,  600);

    }


void DrawSky (COLORREF Color)

    {
    txSetColor (Color,5);
    txSetFillColor (Color);
    txLine (0, 250, 800,  250);
    txFloodFill    (200, 200);
    }


void DrawTree (double x, double y, double up,double angle)

    {
    txSetColor (TX_LIGHTGREEN,6);
    txLine (x+85/up, y+274/up, x+85/up,  y+508/up);
    txLine (x+85/up, y+274/up, x+27/up,  y+328/up+angle);
    txLine (x+85/up, y+274/up, x+150/up, y+335/up+angle);
    txLine (x+85/up, y+340/up, x+30/up,  y+400/up+angle);
    txLine (x+85/up, y+340/up, x+140/up, y+400/up+angle);
    txLine (x+85/up, y+400/up, x+30/up,  y+460/up+angle);
    txLine (x+85/up, y+400/up, x+140/up, y+460/up+angle);
    }

void DrawSun (double x, double y,COLORREF Color)

    {
    txSetFillColor (TX_YELLOW);
    txSetColor (TX_YELLOW,5);
    txCircle (x+80, y+70, 40);
    txSetColor (Color,5);
    txLine (x+70,  y+120, x+50,  y+180);
    txLine (x+100, y+115, x+120, y+170);
    txLine (x+125, y+100, x+170, y+140);
    txLine (x+130, y+60,  x+200, y+80);
    txLine (x+125, y+40,  x+210, y+25);
    }

void DrawBird (double x, double y, double up, double angle) //   angle

    {
    txSetFillColor (TX_PINK);
    txSetColor (TX_PINK,5);
    txEllipse (x+600/up, y+400/up, x+760/up, y+450/up);

    txLine      (x+750/up, y+420/up, x+745/up, y+380/up);
    txLine      (x+745/up, y+380/up, x+790/up, y+400/up);
    txLine      (x+790/up, y+400/up, x+750/up, y+420/up);
    txFloodFill (x+765/up, y+400/up);

    txLine    (x+650/up, y+450/up, x+590/up + angle, y+490/up);  //legs
    txLine    (x+720/up, y+450/up, x+770/up - angle, y+490/up);

    txEllipse (x+560/up, y+370/up, x+620/up, y+400/up);
    txSetColor     (TX_BLACK,5);
    txSetFillColor (TX_BLACK);
    txEllipse (x+575/up, y+380/up, x+595/up, y+385/up);

    txSetFillColor (TX_RED);
    txSetColor     (TX_RED, 5);
    txLine (x+560/up, y+380/up, x+535/up, y+400/up);
    txLine (x+535/up, y+400/up, x+570/up, y+400/up);
    txFloodFill (x+555/up, y+394/up);

    txSetFillColor (TX_PINK);
    txSetColor     (TX_PINK, 5);
    txLine (x+618/up, y+394/up, x+630/up, y+406/up);
    txLine (x+605/up, y+400/up, x+620/up, y+412/up);
    txFloodFill (x+617/up, y+404/up);


    }

void Titr()
    {
    int x=150; int y=800;
    while (y>=0 )
        {
        txTextOut (x, y,    "         This film is about");
        txTextOut (x, y+20, "       little and proud birds");
        txTextOut (x, y+40, " This little birds love the sun very much");
        txTextOut (x, y+60, "       They fly to it every day");
        txTextOut (x, y+80, "       and come out every evening");
        txTextOut (x, y+100, "       ");
        txTextOut (x, y+120, "               The End");
        y-=2;
        txSleep(50);
        txClear();
        }

    }
