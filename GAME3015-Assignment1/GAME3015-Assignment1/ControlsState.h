#pragma once
#include "State.h"

/// <summary>
/// Created the ControlsState
/// </summary>
class ControlsState : public State
{
public:
	SpriteNode* mBackground;

	ControlsState(Game* window);

	void getInputs(const GameTimer& gt) override;
	void draw(const GameTimer& gt) override;
	void update(const GameTimer& gt) override;
	void load() override;

};
