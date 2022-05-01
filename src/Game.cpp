#include "Game.h"
#include <iostream>
#include "raylib.h"

Game::Game() {}
Game::Game(int width, int height)
    : width(width),
      height(height){}

Game::~Game() {}

void Game::addState(const std::shared_ptr<State>& state)
{
    std::cout << "State Added" << std::endl;
    this->stateContainer.push_back(state);
}

void Game::Update(float dt)
{
    for(auto state : stateContainer)
    {
        state->Update(dt);
    }
}

void Game::Draw()
{
    BeginDrawing();
        ClearBackground(BLACK);
        for(auto state : stateContainer)
        {
            state->Draw();
        }
    EndDrawing();
}
