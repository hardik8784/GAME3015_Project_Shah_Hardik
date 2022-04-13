#pragma once
#include "Input.h"
#include "SceneNode.hpp"
#include "SpriteNode.h"
#include "StateList.h"


class State

{

public:

	States mStateType;
	SceneNode* mSceneGraph;
	SceneNode* mWorld;
	ListenerManager	listenerManager;
	Game* mGame;
	float mOrder;

	virtual void getInputs(const GameTimer& gt);
	virtual void draw(const GameTimer& gt);
	virtual void update(const GameTimer& gt);
	virtual void load();

};
