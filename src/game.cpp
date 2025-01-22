#include "game.hpp"

Game :: Game(){

    
}

void Game::Draw(){

    ball.Draw();
}

void Game::Update(){

    ball.ballUpdate();

}
