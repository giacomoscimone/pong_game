#pragma once


class Ball{

    public:
        Ball();
        Ball(int, int);
        
        void Draw();
        void ballUpdate();

        void reboundLines();

        
        bool PointScoredPL1();
        bool PointScoredPL2();

        int x;
        int y;
        int radius;

        void Stop();
        void Start();

    private:
        
        
        double speedX;
        double speedY;    
        
        bool CollisionScreenY();
};