#include "raylib.h"
#include "game.hpp"


int main(){

    InitWindow(1280, 720, "Ping Pong");

    SetTargetFPS(60);

    Color colorBackground = BLACK;

    Game game;

    bool StatusStop = false;

    while( !WindowShouldClose()){

        if(IsKeyPressed(KEY_P))
                StatusStop = !StatusStop;

        ClearBackground( colorBackground );
        BeginDrawing();

        if( !StatusStop ){
            game.HandleInput();

            game.Update();
            if(game.IsEnd)
                game.ResetGame();
        }
        else{
            DrawRectangle(55, 15, 100, 70, WHITE);
        
            DrawRectangle(78, 30, 18, 40, BLACK);
            DrawRectangle(114, 30, 18, 40, BLACK);
        }
        

        game.Draw();

        EndDrawing();
    }

    CloseWindow();
}