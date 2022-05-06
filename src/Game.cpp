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
    this->stateContainer.push_back(state);
}

void Game::Create()
{
    for(auto state : statePtrContainer)
    {
        state->Create();
    }
}

void Game::Update(float dt)
{
    for(auto state : statePtrContainer)
    {
        state->Update(dt);
    }
}

void Game::Draw()
{
    BeginDrawing();
        ClearBackground(BLACK);
        for(auto state : statePtrContainer)
        {
            state->Draw();
        }
    EndDrawing();
}

