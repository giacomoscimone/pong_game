#pragma once
#include "raylib.h"
#include <cmath>
#include <ctime>
#include <string>
#include "iostream"

const int VEL =  14;

#define M_PI 3.14159;

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