#pragma once
#include "raylib.h"

class Page{

    public:
        Page(int);

        int Update();
        void Draw();

    private:
        Rectangle button1 = {200, 250, 170, 50};
        Rectangle button2 = {450, 250, 190, 50};

        const char* question;
        const char* firstChoice;
        const char* secondChoise;
        
        void FirstPage();
        void SecondPage();
};