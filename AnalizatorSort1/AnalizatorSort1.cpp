#include "TXLib.h"
#include "SelectionReady2.cpp"
#include "BubbleReady2.cpp"
#include "InsertionReady2.cpp"
//#include "BinInsertionReady2"
#include "GnomeReady2.cpp"
#include "QuickReady2.cpp"
#include <stdlib.h>



struct MyButton
{
    int xUp, yUp, xDown, yDown;
    char* text;

    void DrawButton();


};


int Analizator(MyButton NumberButton[], int size);
//{----------------------------------------------------------------------------
//!
//}----------------------------------------------------------------------------

int main ()
{
    txCreateWindow (1000, 600);

    MyButton NumberButton [8] = { {50,  100, 220, 150,  "Bubble"},
                                  {50,  150, 220, 200,  "Selection" },
                                  {50,  200, 220, 250,  "Insertion"},
                                  {50,  250, 220, 300,  "BinInsertion"},
                                  {50,  300, 220, 350,  "Gnome"},
                                  {50,  350, 220, 400,  "Quick"},
                                  {50,  450, 220, 500,  "Clear" },
                                  {50,  500, 220, 550,  "Stop" }

                               };
    for (int i = 0; i < 8; i++)
    {
        NumberButton[i].DrawButton();
    }
    txSetColor     (RGB(10,  10,   255),5);
    txSetFillColor (RGB(200, 200,  255));
    txRectangle    (250, 100, 590, 550);
    txRectangle    (600, 100, 950, 550);
    txSetColor     (RGB(200,  200,   255),5);
    txTextOut      (350,  50, "Compare");
    txTextOut      (700,  50, "Exchange");
    txSetColor   (RGB(255, 255,  255),1);



    for  (int y = 100 + 5; y <= 550; y += 10)
    for  (int x = 250 + 5; x <= 590; x += 10)
        txSetPixel ( x, y, RGB(150, 150, 255));

    for  (int y = 100 + 5; y <= 550; y += 10)
    for  (int x = 610;     x <= 940; x += 10)
        txSetPixel ( x, y, RGB(150, 150, 255));



    int number = 10;
    while (number != 7)
    {
        number = Analizator(NumberButton, 8);
        //printf ("%d\n", number);


        if (number == 0)  BubbleReady2();

        if (number == 1)  SelectionReady2();

        if (number == 2)  InsertionReady2();

        //if (number == 3)  BinInsertionReady2();

        if (number == 4)  GnomeReady2();

        if (number == 5)  QuickReady2();

        if (number == 6)
        {
            txSetColor     (RGB(10,  10,   255),5);
            txSetFillColor (RGB(200, 200,  255));
            txRectangle    (250, 100, 590, 550);
            txRectangle    (600, 100, 950, 550);

            //{----------------------------------------------------------------------------
            //!
            //}----------------------------------------------------------------------------

            for  (int y = 100 + 5; y <= 550; y += 10)
            for  (int x = 250 + 5; x <= 590; x += 10)
                txSetPixel ( x, y, RGB(150, 150, 255));

            for  (int y = 100 + 5; y <= 550; y += 10)
            for  (int x = 610;     x <= 940; x += 10)
                txSetPixel ( x, y, RGB(150, 150, 255));



        //{----------------------------------------------------------------------------
        //!
        //}----------------------------------------------------------------------------

        }

    }


    return 0;
}


//{----------------------------------------------------------------------------
//!
//}----------------------------------------------------------------------------


void MyButton:: DrawButton()
{
    txSetColor     (RGB(10,10,255),5);
    txSetFillColor (RGB(100,100,255));
    txRectangle    (xUp,  yUp, xDown, yDown);
    txFloodFill    (xUp + 10,  yUp + 10);
    txSetColor     (RGB(255,200,100),1);
    txTextOut      (xUp + 15,  yUp + 20, text);
}


//{----------------------------------------------------------------------------
//!
//}----------------------------------------------------------------------------

int Analizator(MyButton NumberButton[], int size)
{
    while (1)
    {
        int x = txMouseX(), y = txMouseY();
        for (int i = 0; i < size; i++)
        {
           if (txMouseButtons() && x > NumberButton[i].xUp && y > NumberButton[i].yUp &&
           x < NumberButton[i].xDown && y < NumberButton[i].yDown )
                return i;

        }




    }
    return -1;
}


