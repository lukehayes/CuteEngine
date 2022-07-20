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
			40,
			40,
			RED
			);
}
void Player::update(double dt)
{
}
