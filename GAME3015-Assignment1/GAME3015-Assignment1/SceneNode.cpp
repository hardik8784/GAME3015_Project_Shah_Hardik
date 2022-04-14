#include "SceneNode.hpp"
#include "Game.hpp"
#include <iostream>

SceneNode::SceneNode(Game* game, std::string name) : mChildren(), mParent(nullptr), game(game)
{
	mWorldPosition = XMFLOAT3(0, 0, 0);
	mWorldScaling = XMFLOAT3(1, 1, 1);
	mWorldRotation = XMFLOAT3(0, 0, 0);
}

/// <summary>
/// Add a child to this node
/// </summary>
/// <param name="child"></param>
void SceneNode::attachChild(Ptr child)
{
	child->mParent = this;
	mChildren.push_back(std::move(child));
}

/// <summary>
/// Detaches a child from this node
/// </summary>
/// <param name="node"></param>
/// <returns></returns>
SceneNode::Ptr SceneNode::detachChild(const SceneNode& node)
{
	auto found = std::find_if(mChildren.begin(), mChildren.end(), [&](Ptr& p) { return p.get() == &node; });
	assert(found != mChildren.end());

	Ptr result = std::move(*found);
	result->mParent = nullptr;
	mChildren.erase(found);
	return result;
}

/// <summary>
/// calls the update function of this node and its children
/// </summary>
/// <param name="gt"></param>
void SceneNode::update(const GameTimer& gt)
{
	updateCurrent(gt);
	updateChildren(gt);
}

void SceneNode::updateCurrent(const GameTimer& gt)
{
	// Do nothing by default
}

void SceneNode::updateChildren(const GameTimer& gt)
{
	for (Ptr& child : mChildren)
	{
		child->update(gt);
	}
}

/// <summary>
/// calls the draw function of this node and its children
/// </summary>
void SceneNode::draw() const
{
	drawCurrent();
	drawChildren();
}

void SceneNode::drawCurrent() const
{
	//Empty for now
}

void SceneNode::drawChildren() const
{
	for (const Ptr& child : mChildren)
	{
		child->draw();
	}
}

/// <summary>
/// Calls the build function of this node and its children
/// </summary>
void SceneNode::build()
{
	buildCurrent();
	buildChildren();
}

void SceneNode::DebugSceneNode()
{
	for (int i = 0; i < mChildren.size(); i++)
	{
		std::cout << mChildren[i]->nName << std::endl;
	}

}

void SceneNode::buildCurrent()
{
	//Empty for now
}

/// <summary>
/// Calls the build function of this node's children
/// </summary>
void SceneNode::buildChildren()
{
	for (const Ptr& child : mChildren)
	{
		child->build();
	}
}

/// <summary>
/// Returns the world position of this node
/// </summary>
/// <returns></returns>
XMFLOAT3 SceneNode::getWorldPosition() const
{
	return mWorldPosition;
}

/// <summary>
/// Set the position
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="z"></param>
void SceneNode::setPosition(float x, float y, float z)
{
	mWorldPosition = XMFLOAT3(x, y, z);
}

/// <summary>
/// Returns the world rotation of this node
/// </summary>
/// <returns></returns>
XMFLOAT3 SceneNode::getWorldRotation() const
{
	return mWorldRotation;
}

/// <summary>
/// set the world rotation of this node
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="z"></param>
void SceneNode::setWorldRotation(float x, float y, float z)
{
	mWorldRotation = XMFLOAT3(x, y, z);
}

/// <summary>
///  Scale function
/// </summary>
/// <returns></returns>
XMFLOAT3 SceneNode::getWorldScale() const
{
	return mWorldScaling;
}

/// <summary>
/// setting the Scale function
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="z"></param>
void SceneNode::setScale(float x, float y, float z)
{
	mWorldScaling = XMFLOAT3(x, y, z);
}

/// <summary>
/// Returns the world transform of this node
/// </summary>
/// <returns></returns>
XMFLOAT4X4 SceneNode::getWorldTransform() const
{
	XMFLOAT4X4 transform = MathHelper::Identity4x4();
	XMMATRIX T = XMLoadFloat4x4(&transform);

	for (const SceneNode* node = this; node != nullptr; node = node->mParent)
	{
		XMMATRIX Tp = XMLoadFloat4x4(&node->getTransform());
		T = Tp * T;
	}
	XMStoreFloat4x4(&transform, T);

	return transform;
}

/// <summary>
/// get the transform on each direction
/// </summary>
/// <returns></returns>
XMFLOAT4X4 SceneNode::getTransform() const
{
	XMFLOAT4X4 transform;
	XMStoreFloat4x4(&transform, XMMatrixScaling(mWorldScaling.x, mWorldScaling.y, mWorldScaling.z) *
		XMMatrixRotationX(mWorldRotation.x) *
		XMMatrixRotationY(mWorldRotation.y) *
		XMMatrixRotationZ(mWorldRotation.z) *
		XMMatrixTranslation(mWorldPosition.x, mWorldPosition.y, mWorldPosition.z));
	return transform;
}

/// <summary>
/// Adding movement on every direction
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="z"></param>
void SceneNode::move(float x, float y, float z)
{
	mWorldPosition.x += x;
	mWorldPosition.y += y;
	mWorldPosition.z += z;
}
