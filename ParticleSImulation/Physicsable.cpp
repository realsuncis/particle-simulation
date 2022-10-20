#include "Physicsable.h"
#include "Physics.h"

void Physicsable::updatePhysics()
{
}

Physicsable::Physicsable()
{
	Physics::addPhysicsable(this);
}
