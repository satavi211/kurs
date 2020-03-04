#include <txlib.h>
#include <stdlib.h>

int  Gnome (int data[], int size, int *counterCompare, int *counterExchange );
void DrawGraphick4 (int x, int y, int dx, COLORREF color);
void GnomeReady2();


//int main  ()
//{

    //txCreateWindow (1000, 600);
    //GnomeReady2();
   // return 0;
//}

void GnomeReady2()
{
const int size = 1000;
int data[size] = {};

for ( int number = 1; number < size; number+=10)
{
    int counterCompare = 0, counterExchange = 0;
    for ( int i = 0; i < number; i++)
    {
        data[i] = rand() * 100 + i;
        //printf ("%d\n", data[i]);
    }
    //printf ("\n", "      ");
    Gnome (data, number, &counterCompare, &counterExchange);
    //printf ("%d\n", counterCompare);
    //printf ("%d\n", counterExchange);
    COLORREF color = RGB(255, 255, 0);
    DrawGraphick4(number, counterCompare, 255, color);
    color = RGB(255, 255, 0);
    DrawGraphick4(number, counterExchange, 605, color);
}
}

int Gnome (int data[], int size, int *counterCompare, int *counterExchange )
{
int i = 0;

while (i < size-1)
{
    if (data[i] <= data[i+1])
    {
        i++;
        (*counterCompare) +=1;
    }
    else
    {
        int buffer = data[i];
        data[i] = data[i+1];
        data[i+1] = buffer;
        (*counterExchange) +=1;
        if (i > 0)
        {
            (*counterCompare) +=1;
            i-- ;
        }
     }




}
}
void DrawGraphick4 (int x, int y, int dx, COLORREF color)
{
    txSetColor   (color,3);
    txCircle (x / 3  + dx, - y / 1500 + 545, 2);
}


