#pragma once
#include "Input.h"
#include "Entity.hpp"
#include <string>

class Player :public Entity

{

public:

	Player(Game* game ,std::string name);
	virtual void		input(const GameTimer& gt);

private:

	std::string			mSprite;

	ListenerManager		listenerManager;
	Listener LeftArrowKey;
	Listener RightArrowKey;
	Listener UpArrowKey;
	Listener DownArrowKey;

	virtual void		drawCurrent() const;
	virtual void		buildCurrent();

};
