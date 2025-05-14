#include "game.hpp"
#include "page.hpp"
#include <vector>
using namespace std;

struct Config {

    int gameMode;
    int opponent;
    int difficulty;
};
void DrawPause();
Config Menu();

int main(){

    Config mode = Menu();

    if(mode.gameMode == -1 || mode.opponent == -1)
        return 0;

    InitWindow(1280, 720, "Ping Pong");

    SetExitKey(KEY_NULL);

    SetTargetFPS(60);

    Color colorBackground = BLACK;

    if (mode.opponent == 1 && (mode.difficulty == 1))
            mode.opponent = 2;
    // CPU Easy mode by default


    Game game(mode.gameMode, mode.opponent);

    bool StatusStop = false;

    while( !WindowShouldClose()){

        if(IsKeyPressed(KEY_ESCAPE))
                StatusStop = !StatusStop;

        BeginDrawing();
        ClearBackground( colorBackground );
        if( !StatusStop ){
            game.HandleInput();

            game.Update();
            if(game.IsEnd)
                game.ResetGame();
        }
        else{
            DrawPause();
        }
        
        game.Draw();
        DrawFPS(30, 10);

        EndDrawing();
    }

    CloseWindow();
}

Config Menu(){
    

    InitWindow(800, 600, "Menu'");

    SetExitKey(KEY_NULL);
    

    SetTargetFPS(60);

    // 0 -> default mode, 1 -> speedmode
    int gameMode = -1;
    // 0 -> real player, 1 -> CPU
    int opponent = -1;
    // 0 -> Easy, 1 -> Hard
    int difficulty = -1;

    Page page1(0);
    Page page2(1);
    Page page3(2);

    while (!WindowShouldClose()) {
        
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if( gameMode == -1){
            gameMode = page1.Update();
            page1.Draw();
        }
        else if ( opponent == -1){
            opponent = page2.Update();
            page2.Draw();
        }
        else if (opponent == 1 && difficulty == -1) {
            difficulty = page3.Update();
            page3.Draw();
        }
        else
            break;
        
        EndDrawing();
    }
    CloseWindow();

    
    return {gameMode, opponent, difficulty};

  // #TODO the hard gamemode
}

void DrawPause(){

    DrawRectangle(55, 15, 100, 70, WHITE);
    DrawRectangle(78, 30, 18, 40, BLACK);
    DrawRectangle(114, 30, 18, 40, BLACK);

}

