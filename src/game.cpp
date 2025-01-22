#include "game.hpp"
#include "raylib.h"
#include "ball.hpp"

Game :: Game(){

    scorePl1= 0;
    scorePl2= 0;
}

void Game::Draw(){

    ball.Draw();

    pl1.Draw();
    pl2.Draw();
}

void Game :: Update(){

    pl1.RecUpdate();
    pl2.RecUpdate();


    if(CheckCollisionCircleRec({(float)ball.x , (float)ball.y}, (float)ball.radius, pl1.rec) || CheckCollisionCircleRec({(float)ball.x , (float)ball.y}, (float)ball.radius, pl2.rec) )
        ball.reboundLines();

    ball.ballUpdate();
}
