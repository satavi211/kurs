void DrawSky (COLORREF Color);
void DrawTree (double x, double y, double up,double angle);
void DrawSun (double x,double y,COLORREF Color)  ;
void DrawBird (double x, double y, double up, double angle) ;
void GoodMorning();
void GoodEvening();
void Titr();
void DrawSky (COLORREF Color)

//!  функция рисует елку, у которой можно изменить размер, начальные координаты
//!  елка может махать ветками, вероятно от ветра

void DrawTree (double x, double y, double up, double angle)     x
//!  @param   double x, double y начальные координаты елки
//!  @param   double up параметр, задающий масштаб
//!  @param   double angle  Параметр отвечает за амплитуду размаха ветвей

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
//    Рисует солнце, которое сверкает лучами и может менять свое положение


void DrawSun (double x, double y,COLORREF Color)

//!  @param   double x, double y начальные координаты солнца

//!  @param   COLORREF Color начальный цвет лучей
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

//    рисует гордую маленькую птичку, у которой можно изменять размер, умеет летать при помощи ног

void DrawBird (double x, double y, double up, double angle) //   angle

//!  @param  double x, double y начальные координаты
//!  @param  double up параметр для масштабирования
//!  @param  double angle  размах ног птицы
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
