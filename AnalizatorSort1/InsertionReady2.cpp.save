#include <txlib.h>
#include <stdlib.h>

int Insertion (int data[], int size, int *counterCompare, int *counterExchange );
void DrawGraphick2 (int x, int y, int dx, COLORREF color);
void InsertionReady2();

//int main()
//{
//txCreateWindow (1000, 600);
//InsertionReady2();
//}

void InsertionReady2()
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
    Insertion (data, number, &counterCompare, &counterExchange);
    //printf ("%d\n", counterCompare);
    //printf ("%d\n", counterExchange);
    COLORREF color = RGB(255, 0, 255);
    DrawGraphick2(number, counterCompare, 255, color);
    color = RGB(255, 0, 255);
    DrawGraphick2(number, counterExchange, 605, color);

}
}

int Insertion (int data[], int size, int *counterCompare, int *counterExchange )
{
for (int j = 1; j < size; j++)
{
    int i = j;
    int buffer = data[j];
    while ((i > 0) && (data[i-1] > buffer))
    {
        data[i] = data[i-1];
        i--;
    }
        data[i] = buffer;
        (*counterCompare) +=1;
        (*counterExchange) +=1;
    }
}

}
void DrawGraphick2 (int x, int y, int dx, COLORREF color)
{

    txSetColor   (color,3);
    //for ( int i = 0; i < 450; i++)
    //{
        //printf ("%d\n", y / 1200 );
        txCircle (x / 3  + dx, - y / 1500 + 545, 2);
    //}
}


