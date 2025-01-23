#include "raylib.h"
#include "game.hpp"


int main(){

    InitWindow(1280, 720, "Ping Pong");

    SetTargetFPS(60);

    Color colorBackground = BLACK;

    Game game;

    while( !WindowShouldClose()){

        game.HandleInput();
        
        game.Update();
        ClearBackground( colorBackground );
        BeginDrawing();
        
        game.Draw();

        if(game.IsEnd)
            game.ResetGame();

        EndDrawing();
    }

    CloseWindow();
}