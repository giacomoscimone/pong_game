#include "line.hpp"
#include "raylib.h"

Line :: Line(bool numberPlayer){

    if(numberPlayer)
        x = 120;

    else 
        x = GetScreenWidth() - 120;


    y = GetScreenHeight() / 2;

    speedY = 7.5;
}

void Line :: RecUpdate(){

    rec.x = x;
    rec.y = y;
    rec.width = WIDTH;
    rec.height = HEIGHT;
}

void Line :: Draw(){

    DrawRectangle(x, y, WIDTH, HEIGHT, WHITE);
}



void Line :: MoveUp(){

    if( y >= 0 )
        y -= speedY;
}

void Line :: MoveDown(){

    if( y + HEIGHT <= GetScreenHeight() )
        y += speedY;
}
