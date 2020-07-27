#pragma once
#include <map>
#include <SFML/Graphics.hpp>

class RigidBody : 
	public sf::Sprite
{
private:
	static int bodyID;
	static std::map<int, RigidBody*> object_list;
	int selfID;

	float gravity;
public:
	bool is_static;

	// Constructor
	RigidBody();
	//Deconstructer
	~RigidBody();

	// Methods
	void update(sf::Time dt);
};

