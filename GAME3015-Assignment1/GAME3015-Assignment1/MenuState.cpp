#include "MenuState.h"
#include <iostream>

MenuState::MenuState(Game* window)
{
	mGame = window;
	mSceneGraph = new SceneNode(window, "Menu State");
	mBackground = nullptr;
	mArrow = nullptr;
	option = 0;
	mStateType = States::MENU_STATE;
	mOrder = 1;
}

void MenuState::getInputs(const GameTimer& gt)
{
	if (listenerManager.CheckListener(up))
	{
		if (option == 1)
		{
			mArrow->setPosition(-1.4f, 0.26, 0);
			option = 0;

		}
	}
	else if (listenerManager.CheckListener(down))
	{
		if (option == 0)
		{
			mArrow->setPosition(-1.5f, -1.125f, 0);
			option = 1;

		}
	}

	if (listenerManager.CheckListener(quit))
	{
		exit(1);
	}
}

void MenuState::draw(const GameTimer& gt)
{
	mSceneGraph->draw();
}

void MenuState::update(const GameTimer& gt)
{
	mSceneGraph->setPosition(0, 0, 2 * mOrder);
	mSceneGraph->update(gt);
	getInputs(gt);
}

void MenuState::load()
{
	std::unique_ptr<SpriteNode> selector(new SpriteNode(mGame, "Selector", "Arrow"));
	mArrow = selector.get();
	mArrow->setPosition(-1.4f, 0.26, 0 );
	mArrow->setScale(0.3, 0.3, 0.3);
	mArrow->setWorldRotation(90 * XM_PI / 180, 0, 180 * XM_PI / 180);
	mSceneGraph->attachChild(std::move(selector));

	std::unique_ptr<SpriteNode> menubg(new SpriteNode(mGame, "Menu", "BG"));
	mBackground = menubg.get();
	mBackground->setPosition(0, 0, 1 + mOrder);
	mBackground->setScale(15.0, 1.0, 10 );
	mBackground->setWorldRotation(90 * XM_PI / 180, 0, 180 * XM_PI / 180);
	mSceneGraph->attachChild(std::move(menubg));
	mSceneGraph->build();

	//up arrow
	up.bindInt = 0x26;

	//down arroe
	down.bindInt = 0x28;

	//quit
	quit.bindInt = 0x1B;


	listenerManager.AddListener(up);
	listenerManager.AddListener(down);
}
