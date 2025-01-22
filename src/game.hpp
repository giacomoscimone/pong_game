#pragma once
#include "ball.hpp"
#include "line.hpp"


class Game{

    public:
        Game();
        
        void Draw();
        void Update();

        int scorePl1;
        int scorePl2;

    private:
        Ball ball;

        Line pl1 = Line(0);
        Line pl2 = Line(1);


};