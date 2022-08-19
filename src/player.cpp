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
			BLUE
			);

	this->drawCollisionRect();
}
void Player::update(double dt)
{
}
