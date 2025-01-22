#pragma once
#include "ball.hpp"
#include "line.hpp"


class Game{

    public:
        Game();
        
        void Draw();
        void Update();

        void HandleInput();

        int scorePl1;
        int scorePl2;

    private:
        Ball ball;

        Line pl1 = Line(1);
        Line pl2 = Line(0);


};