#pragma once
#include "raylib.h"
#include <cmath>
#include <ctime>
#include <string>
#include "iostream"

#define M_PI 3.14159;

class Ball{

    public:
        Ball();
        Ball(int, int);
        
        void Draw();
        void ballUpdate();

        void reboundLines(bool, Rectangle);
        void UpdateSpeed();
        void CorrectAngle();
        void Accellerate();
        
        bool PointScoredPL1();
        bool PointScoredPL2();

        int x;
        int y;
        int radius;

        void Stop();
        void Start();

    private:
        
        int VEL;

        double angle;

        double speedX;
        double speedY;
        
        bool CollisionScreenY();
};