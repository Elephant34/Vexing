#pragma once
#include <map>
#include <SFML/Graphics.hpp>

class RigidBody : 
	public sf::Sprite
{
private:
	float gravity;
public:
	bool is_static;

	// Constructor
	RigidBody();

	// Methods
	void update(sf::Time dt);
	void update(sf::Time dt, std::vector<RigidBody> collision_objects);

	bool on_floor(std::vector<RigidBody> collision_objects);
};

