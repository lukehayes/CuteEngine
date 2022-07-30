#include "entity/player.h"
#include <iostream>
#include <cmath>

Player::Player() {}
Player::~Player() {}

void Player::render()
{
	DrawRectangle(
			position.x,
			position.y,
			size.x,
			size.y,
			RED
			);
}
void Player::update(double dt)
{
}
