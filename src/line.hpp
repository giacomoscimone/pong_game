#pragma once
#include "raylib.h"

class Line{

    public:
        Line();
        Line(bool);

        void Draw();
        void RecUpdate();

        bool isFirstPl;

        Rectangle rec;

        void MoveUp();
        void MoveDown();

        void Stop();
        void Start();

    private:

        int x;
        int y;

        const int WIDTH = 25, HEIGHT = 130;
        
        int speedY;
};