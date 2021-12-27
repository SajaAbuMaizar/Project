#pragma once
#include "GameObject.h"

class MovingObject : public GameObject
{
public:
	using GameObject::GameObject;
	virtual void move() = 0;
	virtual void speed() = 0;

private:

};