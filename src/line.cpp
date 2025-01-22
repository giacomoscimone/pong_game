#include "line.hpp"
#include "raylib.h"

Line :: Line(bool numberPlayer){

    if(numberPlayer)
        x = 100;

    else 
        x = GetScreenWidth() - 100;


    y = GetScreenHeight() / 2;
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

