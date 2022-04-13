#pragma once
#include "State.h"

class MenuState : public State
{
public:

	SceneNode* mSceneGraph;
	int option;

	MenuState(Game* window);

	void getInputs(const GameTimer& gt) override;
	void draw(const GameTimer& gt) override;
	void update(const GameTimer& gt) override;
	void load() override;

private:

	Game* mGame;
	ListenerManager	listenerManager;
	SpriteNode* mBackground;
	SpriteNode* mArrow;
	Listener up;
	Listener down;
	Listener quit;
};
