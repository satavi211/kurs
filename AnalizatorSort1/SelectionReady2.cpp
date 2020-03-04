#include <txlib.h>
#include <stdlib.h>

int Selection (int data[], int size, int *counterCompare, int *counterExchange );
void DrawGraphick(int x, int y, int dx, COLORREF color);
void SelectionReady2();

//int main  ()
//{

//
//txCreateWindow (1000, 600);
//SelectionReady();
//return 0;
//}

void SelectionReady2()
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
        Selection (data, number, &counterCompare, &counterExchange);
        //printf ("%d\n", counterCompare);
        //printf ("%d\n", counterExchange);
        COLORREF color = RGB(0, 255, 255);
        DrawGraphick(number, counterCompare, 255, color);
        color = RGB(0, 255, 255);
        DrawGraphick(number, counterExchange, 605, color);
    }
}

int Selection (int data[], int size, int *counterCompare, int *counterExchange )

{
    for (int j = 0; j < size-1; j++)
    {
        int maxim = j;
        for (int i = j+1; i < size; i++)
        {
            if (data[i] < data[maxim])
                maxim = i;
        (*counterCompare) +=1;
        }
    int buffer = data[j];
    data[j] = data[maxim];
    data[maxim] = buffer;
    (*counterExchange) +=1;
    }


}
void DrawGraphick (int x, int y, int dx, COLORREF color)
{

    txSetColor   (color,3);
    txCircle (x / 3  + dx, - y / 1500 + 545, 2);
}
