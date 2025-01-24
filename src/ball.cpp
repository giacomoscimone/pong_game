#include "ball.hpp"
#include "raylib.h"
#include <random>


Ball :: Ball(){

    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;

    Start();

    radius = 13;
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

    if(CollisionScreenY())
        speedY = -speedY;

    x += speedX;
    y += speedY;
}

void Ball :: reboundLines(bool pl){

    speedX = 10;

    if(rand()%2)
        speedY = -speedY;

    y += rand()%8 -4;

    if(pl)
        speedX = -speedX;
}

bool Ball :: CollisionScreenY(){


    return (y + radius >= GetScreenHeight() && speedY > 0) || (y - radius <= 0 && speedY < 0);
}

bool Ball :: PointScoredPL1(){

    return (x + radius >= GetScreenWidth() && speedX > 0);
}

bool Ball :: PointScoredPL2(){
    return (x - radius <= 0 && speedX < 0);
}


void Ball :: Stop(){

    speedX = 0;
    speedY = 0;
}

void Ball :: Start(){

    speedX = 7;
    speedY = 7;

    if(rand()%2)
        speedX = -speedX;
    if(rand()%2)
        speedY = -speedY;
}