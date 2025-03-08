#include "game.hpp"
#include "raylib.h"
#include "ball.hpp"
#include "line.hpp"
#include <iostream>

Game :: Game(){

    Start();

}

void Game :: Draw(){

    int i = 30;

    while( i <= GetScreenHeight() - 90 ){
        DrawRectangle( GetScreenWidth()/2 - 17/2, i, 17, 60, WHITE);
        i += 120;
    }

    std :: string s1 = std :: to_string(scorePl1);
    std :: string s2 = std :: to_string(scorePl2);
    char const *score1 = s1.c_str();
    char const *score2 = s2.c_str();

    DrawText(score1, GetScreenWidth()/2 - 160, 10, 80, WHITE);
    DrawText(score2, GetScreenWidth()/2 + 120, 10, 80, WHITE);

    ball.Draw();

    pl1.Draw();
    pl2.Draw();
}

void Game :: Update(){


    pl1.RectUpdate();
    pl2.RectUpdate();


    if(CheckCollisionCircleRec({(float)ball.x , (float)ball.y}, (float)ball.radius, pl1.rect) )
        ball.reboundLines(0, pl1.rect);
    else if(CheckCollisionCircleRec({(float)ball.x , (float)ball.y}, (float)ball.radius, pl2.rect))
        ball.reboundLines(1, pl2.rect);
        
    if(timeAttend <= 0)
        ball.ballUpdate();
    else {
        timeAttend --;
        // a animation of circle that close in the time
    }
    if(ball.PointScoredPL1()){
        AddScorePl1();
        ball = Ball();
        timeAttend = 15;
    }
    else if(ball.PointScoredPL2()){
        AddScorePl2();
        ball = Ball();
        timeAttend = 15;
    }
        
    
}

void Game :: HandleInput(){


    if(IsKeyDown(KEY_W))
        pl1.MoveUp();
    else if(IsKeyDown(KEY_S))
        pl1.MoveDown();
    if(IsKeyDown(KEY_UP))
        pl2.MoveUp();
    else if(IsKeyDown(KEY_DOWN))
        pl2.MoveDown();
    
}

void Game :: ResetGame(){

    ball.Stop();
    pl1.Stop();
    pl2.Stop();
    
    std :: string textWinner = "";
    
    if(scorePl1 > scorePl2)
        textWinner = "Player 1";
    else 
        textWinner = "Player 2";

    char const* winner = textWinner.c_str();


    DrawRectangle(GetScreenWidth()/2 - 320, GetScreenHeight()/2 - 120, 550, 330, BLACK);
    DrawText("The Winner Is", GetScreenWidth()/2 - 300, GetScreenHeight()/2 - 120, 80, WHITE);
    DrawText(winner, GetScreenWidth()/2 - 270, GetScreenHeight()/2, 80, WHITE);

    DrawText("Press the Spacebar for restart", GetScreenWidth()/2 - 250, GetScreenHeight()/2 + 210, 30, WHITE);
    
    if(IsKeyDown(KEY_SPACE))
        Start();
         
}

void Game :: AddScorePl1(){
    
    scorePl1++;

    if(scorePl1 >= MAX_SCORE)
        IsEnd = true;
}

void Game :: AddScorePl2(){

    scorePl2++;

    if(scorePl2 >= MAX_SCORE)
        IsEnd = true;
}


void Game :: Start(){
    
    IsEnd = false;

    ball.Start();

    pl1.Start();
    pl2.Start();


    scorePl1= 0;
    scorePl2= 0;
}
