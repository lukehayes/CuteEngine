#include "State.h"
#include <iostream>

State::State() {}
State::~State() {}


void State::Update(float dt)
{
    std::cout << "Updating..." << std::endl;
}
