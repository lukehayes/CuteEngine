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

void Game::Create()
{
    std::cout << "Game Create" << std::endl;
    for(auto state : statePtrContainer)
    {
        state->Create();
    }
}

void Game::Update(float dt)
{
    std::cout << statePtrContainer.size() << std::endl;
    std::cout << "Game Update" << std::endl;
    for(auto state : statePtrContainer)
    {
        state->Update(dt);
    }
}

void Game::Draw()
{
    std::cout << "Game Draw" << std::endl;
    BeginDrawing();
        ClearBackground(BLACK);
        for(auto state : statePtrContainer)
        {
            state->Draw();
        }
    EndDrawing();
}

