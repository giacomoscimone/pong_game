#include "ball.hpp"
#include "raylib.h"


Ball :: Ball(){

    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;

    speedX = 4.5;
    speedY = 4.5;

    radius = 15;
}

Ball :: Ball( int X, int Y){

    Ball();

    x = X;
    y = Y;

}


void Ball :: Draw(){

    DrawCircle(x, y, radius, WHITE);
}

void Ball :: ballUpdate(){

    if(CollisionScreenX())
        speedX = -speedX;
    
    if(CollisionScreenY())
        speedY = -speedY;

    x += speedX;
    y += speedY;
}

void Ball :: reboundLines(){

    speedX = -speedX;
    speedY = -speedY;
}

bool Ball :: CollisionScreenX(){


    return (x + radius >= GetScreenWidth() && speedX > 0) || (x - radius <= 0 && speedX < 0);
}

bool Ball :: CollisionScreenY(){


    return (y + radius >= GetScreenHeight() && speedY > 0) || (y - radius <= 0 && speedY < 0);
}