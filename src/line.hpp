#pragma once
#include "raylib.h"

class Line{

    public:
        Line(bool);

        void Draw();
        void RecUpdate();

        bool isFirstPl;

        Rectangle rec;

    private:

        int x;
        int y;

        const int WIDTH = 25, HEIGHT = 130;
        

};