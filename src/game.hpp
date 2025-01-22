#pragma once
#include "ball.hpp"


class Game{

    public:
        Game();
        
        void Draw();
        void Update();

    private:
        Ball ball;


};