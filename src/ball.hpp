#pragma once
#include "raylib.h"
#include <cmath>
#include <iostream>

const int VEL =  12;

class Ball{

    public:
        Ball();
        Ball(int, int);
        
        void Draw();
        void ballUpdate();

        void reboundLines(bool, Rectangle);

        
        bool PointScoredPL1();
        bool PointScoredPL2();

        int x;
        int y;
        int radius;

        void Stop();
        void Start();

    private:
        
        double angle;

        double speedX;
        double speedY;
        
        bool CollisionScreenY();
};