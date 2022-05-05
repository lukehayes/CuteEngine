#include "BasicObject.h"
#include <iostream>

#include "Game.h"

BasicObject::BasicObject()
{
    std::cout << "BasicObject Created" << std::endl;
}

BasicObject::~BasicObject() { std::cout << "BasicObject Destroyed" << std::endl;}
