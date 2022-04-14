#include "Entity.hpp"

Entity::Entity(Game* game, std::string name) : SceneNode(game, name), mVelocity(0, 0)
{
	mName = name;
}

/// <summary>
/// Sets the velocity of the entity
/// </summary>
/// <param name="velocity"></param>
void Entity::setVelocity(XMFLOAT2 velocity)
{
	mVelocity = velocity;
}

/// <summary>
/// set the velocity on x and y direction
/// </summary>
/// <param name="vx"></param>
/// <param name="vy"></param>
void Entity::setVelocity(float vx, float vy)
{
	mVelocity.x = vx;
	mVelocity.y = vy;
}

/// <summary>
/// returns the velocity of the entity
/// </summary>
/// <returns></returns>
XMFLOAT2 Entity::getVelocity() const
{
	return mVelocity;
}

void Entity::updateCurrent(const GameTimer& gt) 
{
	XMFLOAT2 mV;
	mV.x = mVelocity.x * gt.DeltaTime();
	mV.y = mVelocity.y * gt.DeltaTime();

	move(mV.x, mV.y, 0);

	renderer->World = getWorldTransform();
	renderer->NumFramesDirty++;
}

