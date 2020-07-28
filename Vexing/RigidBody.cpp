#include <iostream>
#include <map>
#include "RigidBody.h"

RigidBody::RigidBody()
{
	is_static = true;
	gravity = 200.f;
}

void RigidBody::update(sf::Time dt)
{
	if (!is_static) {

		move(0.f, gravity*dt.asSeconds());
	}
}

void RigidBody::update(sf::Time dt, std::vector<RigidBody> collision_objects)
{
	if (!is_static && !on_floor(collision_objects)) {
		move(0.f, gravity * dt.asSeconds());
	}
}

bool RigidBody::on_floor(std::vector<RigidBody> collision_objects)
{
	sf::FloatRect selfRect = getGlobalBounds();
	float selfBottom = selfRect.top + selfRect.height;

	bool collision = false;

	for (RigidBody object : collision_objects)
	{
		sf::FloatRect objectRect = object.getGlobalBounds();

		if (
			selfBottom < (objectRect.top + objectRect.height)
			&& selfBottom > objectRect.top
			)
		{
			collision = true;
		}
	}
	return collision;
}
