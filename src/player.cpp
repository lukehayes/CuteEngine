#include "entity/player.h"
#include <iostream>
#include "raylib.h"
#include <cmath>
Player::Player(const Vector2& position)
	: Entity(position, {50,50}),
		color({50,50,100, 255})

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
