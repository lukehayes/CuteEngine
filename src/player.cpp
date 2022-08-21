#include "entity/player.h"
#include "raylib.h"
#include <cmath>
#include <iostream>

Player::Player(const Vector2& position)
	: Entity(position, {50,50}),
		color({50,50,100, 255})

{}
Player::~Player() {}

void Player::render()
{
	DrawRectangle(
			position.x,
			position.y,
			size.x,
			size.y,
			color
			);

	// this->drawCollisionRect();
}
void Player::update(double dt)
{
	shoot();
}

void Player::shoot()
{
	if(IsKeyPressed(KEY_SPACE))
	{
		std::cout << "Shoot" << std::endl;
	}
}
