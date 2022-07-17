#pragma once

/**
 * Base game object that most entities should inherit.
 */
class GameObject
{
	public:

		GameObject();
		~GameObject();

		virtual void render() = 0;
		virtual void update(double dt) = 0;
};
