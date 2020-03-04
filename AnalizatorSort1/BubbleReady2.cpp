#include <txlib.h>
#include <stdlib.h>

int Bubble (int data[], int size, int *counterCompare, int *counterExchange );
void DrawGraphick1 (int x, int y, int dx, COLORREF color);
void BubbleReady2();


//int main  ()
//{

   //txCreateWindow (1000, 600);
    //BubbleReady2();
    //return 0;
//}

void BubbleReady2()
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
    Bubble (data, number, &counterCompare, &counterExchange);
    //printf ("%d\n", counterCompare);
    //printf ("%d\n", counterExchange);

    COLORREF color = RGB(0, 255, 0);
    DrawGraphick1(number, counterCompare, 255, color);

    color = RGB(0, 255, 0);
    DrawGraphick1(number, counterExchange, 605, color);

}
}

int Bubble (int data[], int size, int *counterCompare, int *counterExchange )
{
for (int j = 0; j < size-1; j++)
{
    for (int i = size-1; i>j; i--)
    {
        if (data[i] < data[i-1])
        {
            int buffer = data[i];
                data[i] = data[i-1];
                data[i-1] = buffer;
                (*counterExchange) +=1;
        }
    (*counterCompare) +=1;

     }

}
}
void DrawGraphick1 (int x, int y, int dx, COLORREF color)
{
    txSetColor   (color,3);
    txCircle (x / 3  + dx, - y / 1500 + 545, 2);

}


