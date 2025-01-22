#pragma once


class Ball{

    public:
        Ball();
        Ball(int, int);
        
        void Draw();
        void ballUpdate();

        void reboundLines();

        int x;
        int y;
        int radius;

    private:
        
        
        double speedX;
        double speedY;    

        bool CollisionScreenX();
        bool CollisionScreenY();
};