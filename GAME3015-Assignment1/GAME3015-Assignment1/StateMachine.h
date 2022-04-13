#pragma once
#include "TitleState.h"
#include "MenuState.h"
#include "GameState.h"
#include "ControlsState.h"
#include "StateList.h"

class StateMachine

{

public:

	StateMachine(Game* game);
	void draw(const GameTimer& gt);
	void input(const GameTimer& gt);
	void update(const GameTimer& gt);
	void SetState(State* s);
	void load();

private:

	Game* mGame;
	std::vector<State*> states;
	TitleState* titleState;
	MenuState* menuState;
	GameState* gameState;
	ControlsState* controlsState;
	ListenerManager listeners;
	Listener enterKey;
	Listener backspaceKey;
	Listener pause;

};