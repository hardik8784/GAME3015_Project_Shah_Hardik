#include "ControlsState.h"

ControlsState::ControlsState(Game* window)
{
	mGame = window;
	mSceneGraph = new SceneNode(window, "Controls State");
	mBackground = nullptr;
	mStateType = States::PAUSE_STATE;
	mOrder = 2;
}

void ControlsState::getInputs(const GameTimer& gt)
{

}

void ControlsState::draw(const GameTimer& gt)
{
	mSceneGraph->draw();
}

void ControlsState::update(const GameTimer& gt)
{
	mSceneGraph->setPosition(0, 0, 2 * mOrder);
	mSceneGraph->update(gt);
}

void ControlsState::load()
{
	std::unique_ptr<SpriteNode> bg(new SpriteNode(mGame, "Controls", "Bg"));
	mBackground = bg.get();
	mBackground->setPosition(0, 0, 1 + mOrder);
	mBackground->setScale(15.0, 1.0, 11.0);
	mBackground->setWorldRotation(90 * XM_PI / 180, 0, 180 * XM_PI / 180);
	mSceneGraph->attachChild(std::move(bg));
	mSceneGraph->build();
}
