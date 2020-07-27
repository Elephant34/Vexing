#include <iostream>
#include <map>
#include "RigidBody.h"

int RigidBody::bodyID = 0;
std::map<int, RigidBody*> RigidBody::object_list;

RigidBody::RigidBody()
{
	selfID = bodyID++;
	object_list[selfID] = this;

	is_static = true;
	gravity = 200.f;
}

RigidBody::~RigidBody()
{
	object_list.erase(selfID);
}

void RigidBody::update(sf::Time dt)
{
	if (!is_static) {

		move(0.f, gravity*dt.asSeconds());
	}
}
