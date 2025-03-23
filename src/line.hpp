#pragma once
#include "raylib.h"

class Line{

    public:
        // Line();
        Line(bool);

        void Reduce();

        void Draw();
        void RectUpdate();

        bool isFirstPl;

        Rectangle rect;

        void MoveUp();
        void MoveDown();

        void Stop();
        void Start();

    private:

        int x;
        int y;

        const int WIDTH = 25;
        int HEIGHT;
        
        int speedY;
};