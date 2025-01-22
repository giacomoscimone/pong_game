#pragma once


class Ball{

    public:
        Ball();
        Ball(int, int);
        
        void Draw();
        void ballUpdate();

    private:
        int x;
        int y;
        int radius;
        
        double speedX;
        double speedY;    

        bool CollisionScreenX();
        bool CollisionScreenY();
};