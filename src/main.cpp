#include "game.hpp"
#include "page.hpp"
#include <vector>
using namespace std;

void DrawPause();
vector<int> Menu();

int main(){

    vector<int> mode = Menu();

    if(mode[0] == -1 || mode[1] == -1)
        return 0;

    InitWindow(1280, 720, "Ping Pong");

    SetExitKey(KEY_NULL);

    SetTargetFPS(60);

    Color colorBackground = BLACK;

    Game game(mode[0], mode[1]);

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

        EndDrawing();
    }

    CloseWindow();
}

vector<int> Menu(){
    

    InitWindow(800, 600, "Menu'");

    SetExitKey(KEY_NULL);
    

    SetTargetFPS(60);

    // 0 -> default mode, 1 -> speedmode
    int gameMode = -1;
    // 0 -> real player, 1 -> CPU
    int opponent = -1;

    Page page1(0);
    Page page2(1);

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
        else
            break;
        
        EndDrawing();
    }
    CloseWindow();

    std::vector <int> result;

    result.push_back(gameMode);
    result.push_back(opponent);

    return result;

}

void DrawPause(){

    DrawRectangle(55, 15, 100, 70, WHITE);
    DrawRectangle(78, 30, 18, 40, BLACK);
    DrawRectangle(114, 30, 18, 40, BLACK);

}