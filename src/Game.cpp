#include "Game.h"
#include <iostream>

Game::Game() {}
Game::Game(int width, int height)
    : width(width),
      height(height){}

Game::~Game() {}

void Game::addState(const State& state)
{
    std::cout << "State Added" << std::endl;
    this->stateContainer.push(state);
}

void Game::Update(float dt)
{
    for(auto state : stateContainer)
    {
        state.Update(dt);
    }
}
