#include "raylib.h"


int main(){

    InitWindow(1280, 720, "Ping Pong");

    SetTargetFPS(60);

    Color colorBackground = BLACK;

    while( !WindowShouldClose()){
        
        ClearBackground( colorBackground );
        BeginDrawing();
        
        

        EndDrawing();
    }

    CloseWindow();
}