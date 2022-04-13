#pragma once
#include "State.h"

class TitleState : public State

{

public:

	SpriteNode* mBg;

	TitleState(Game* window);
	void getInputs(const GameTimer& gt) override;
	void draw(const GameTimer& gt) override;
	void update(const GameTimer& gt) override;
	void load() override;

};
