#include "ball.hpp"

const float MAX_ANGLE = PI / 4;


Ball :: Ball(){

    srand(time(NULL));

    Start();

    angle = 0;

    radius = 13;
}

Ball :: Ball( int X, int Y){

    Ball();

    x = X;
    y = Y;

}


void Ball :: Draw(){

    DrawCircle(x, y, (float)radius, WHITE);

    DrawText(std::to_string(angle*180/PI).c_str(), 200, 200, FONT_DEFAULT, WHITE);
}

void Ball :: ballUpdate(){

    if(CollisionScreenY()){
        angle = -angle;
        CorrectAngle();

        if(speedX < 0)
            speedX = -VEL * cos(angle);
        else 
            speedX = VEL * cos(angle);
        speedY = VEL * sin(angle);
    }

    x += (int)speedX;
    y += (int)speedY;
}

void Ball :: reboundLines(bool pl, Rectangle paddle){


    float impact = (y + radius - paddle.y) / (paddle.height / 2);
    if (impact > 1) impact = 1;  
    if (impact < -1) impact = -1; 

    angle = impact * MAX_ANGLE;

    angle += ((float)rand() / RAND_MAX) * 0.5 - 0.25;

    CorrectAngle();

    speedX = VEL * std::abs(cos(angle));
    if(pl)
        speedX = -speedX;

    speedY = VEL * sin(angle);
    
}

void Ball::CorrectAngle(){
    float angleGrad = angle*180 / PI;
    float radAngle = PI/180;

    if( angleGrad >= 50 && angleGrad <= 90 )
        angle = radAngle * 50;
    else if( angleGrad <= 130 && angleGrad >= 90 )
        angle = radAngle * 140;
    else if( angleGrad >= 270 && angleGrad <= 310 )
        angle = radAngle * 310;
    else if( angleGrad >= 230 && angleGrad <= 270 )
        angle = radAngle * 230;
}

void Ball::Accellerate(){

    VEL += 0.2;
}

bool Ball :: CollisionScreenY(){


    return (y + radius >= GetScreenHeight() && speedY > 0) || ( (y - radius <= 0) && speedY < 0 );
}

bool Ball :: PointScoredPL1(){

    return (x + radius >= GetScreenWidth());
}

bool Ball :: PointScoredPL2(){
    return (x - radius <= 0);
}


void Ball :: Stop(){

    speedX = 0;
    speedY = 0;
}

void Ball :: Start(){

    VEL = 13;

    double possAngles[] = {0, 45, 150, 180, 200, 315};

    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;

    int size = sizeof(possAngles) / sizeof(possAngles[0]);

    angle = possAngles[rand() % size] * (PI / 180.0);

    speedX = VEL * cos(angle);
    speedY = VEL * sin(angle);
}