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

        void ResetGame();

        bool IsEnd;
        void Start();

    private:
        Ball ball;

        Line pl1 = Line(1);
        Line pl2 = Line(0);

        double timeAttend = 0;

        void AddScorePl1();
        void AddScorePl2();

        const int MAX_SCORE = 10;


};