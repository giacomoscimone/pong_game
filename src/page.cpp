#include "page.hpp"

Page::Page(int n){

    switch (n){

    case 0:
        FirstPage();
        break;
    
    case 1:
        SecondPage();
        break;

    default:
        break;
    }
    
}

int Page :: Update(){
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePoint = GetMousePosition();

        if (CheckCollisionPointRec(mousePoint, button1)) {
            return 0; 
        }
        if (CheckCollisionPointRec(mousePoint, button2)) {
            return 1;
        }
    }
    
    return -1;
}

void Page::Draw()
{

    DrawText(question, 280, 180, 20, DARKGRAY);

    DrawRectangleRec(button1, LIGHTGRAY);
    DrawRectangleRec(button2, LIGHTGRAY);
    DrawText(firstChoice, button1.x + 20, button1.y + 10, 20, BLACK);
    DrawText(secondChoise, button2.x + 20, button2.y + 10, 20, BLACK);
}

void Page :: FirstPage(){

    question = "Select Mode:";
    firstChoice = "Classic mode";
    secondChoise = "Competitive mode";

}

void Page :: SecondPage(){

    question = "How you want to play?";
    firstChoice = "Vs Player";
    secondChoise = "Vs Computer";
}