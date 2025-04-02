#include "line.hpp"


Line :: Line(bool numberPlayer){

    Start();

    if(numberPlayer)
        x = 120;

    else 
        x = GetScreenWidth() - 120;


    y = GetScreenHeight() / 2;

}

void Line :: RectUpdate(){

    rect.x = x;
    rect.y = y;
    rect.width = WIDTH;
    rect.height = HEIGHT;
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

void Line :: Stop(){

    speedY = 0;
}

void Line :: Start(){

    speedY = 7.5;
    HEIGHT = 130;
}

int Line :: AboveBall(int Y){

    if(Y < y + tolleranceHeight)
        return 1;
    else if(Y > y + tolleranceHeight)
        return 0;
    else
        return -1;
}

void Line :: Reduce(){

    if(HEIGHT >= 40){
        HEIGHT -= 1;
        y++;
    }
    speedY += 0.15;

}