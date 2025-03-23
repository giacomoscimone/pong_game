#include "game.hpp"

void DrawPause();
bool Menu();

int main(){

    bool mode = Menu();

    InitWindow(1280, 720, "Ping Pong");

    SetExitKey(KEY_NULL);

    SetTargetFPS(60);

    Color colorBackground = BLACK;

    Game game(mode);

    bool StatusStop = false;

    while( !WindowShouldClose()){

        if(IsKeyPressed(KEY_P))
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

bool Menu(){
    

    InitWindow(800, 600, "Esempio di due bottoni");

    SetExitKey(KEY_NULL);
    

    SetTargetFPS(60);

    int result = -1;

    Rectangle button1 = {200, 250, 170, 50};
    Rectangle button2 = {450, 250, 190, 50};

    while (!WindowShouldClose()) {
        
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePoint = GetMousePosition();

            if (CheckCollisionPointRec(mousePoint, button1)) {
                result = 0;
                break; 
            }
            if (CheckCollisionPointRec(mousePoint, button2)) {
                result = 1;
                break;
            }
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Scegli la modalita'", 280, 180, 20, DARKGRAY);

        DrawRectangleRec(button1, LIGHTGRAY);
        DrawRectangleRec(button2, LIGHTGRAY);
        DrawText("Classic mode", button1.x + 20, button1.y + 10, 20, BLACK);
        DrawText("Competitive mode", button2.x + 20, button2.y + 10, 20, BLACK);

        EndDrawing();
    }
    CloseWindow();

    return result;

}

void DrawPause(){

    DrawRectangle(55, 15, 100, 70, WHITE);
    DrawRectangle(78, 30, 18, 40, BLACK);
    DrawRectangle(114, 30, 18, 40, BLACK);

}