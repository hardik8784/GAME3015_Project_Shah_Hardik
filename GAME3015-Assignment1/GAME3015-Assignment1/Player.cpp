#include "Player.h"
#include "Game.hpp"

/// <summary>
/// Constructor for the Player
/// </summary>
/// <param name="game"></param>
/// <param name="name"></param>
Player::Player(Game* game, std::string name) : Entity(game, name)
{
	mSprite = "Eagle";
	mName = "Player";

	//bind arrow keys
	LeftArrowKey.bindInt = 0x25;
	RightArrowKey.bindInt = 0x27;
	UpArrowKey.bindInt = 0x26;
	DownArrowKey.bindInt = 0x28;

	listenerManager.AddListener(LeftArrowKey);
	listenerManager.AddListener(RightArrowKey);
	listenerManager.AddListener(UpArrowKey);
	listenerManager.AddListener(DownArrowKey);
}

/// <summary>
/// Check the Inputs
/// </summary>
/// <param name="gt"></param>
void Player::input(const GameTimer& gt)
{
	float speed = 2.0f * gt.DeltaTime();
	
	if (listenerManager.CheckListener(LeftArrowKey))
	{
		move(-speed, 0, 0);
	}

	if (listenerManager.CheckListener(RightArrowKey))
	{
		move(speed, 0, 0);
	}

	if (listenerManager.CheckListener(UpArrowKey))
	{
		move(0, speed, 0);
	}
	
	if (listenerManager.CheckListener(DownArrowKey))
	{
		move(0, -speed, 0);
	}
}

void Player::drawCurrent() const
{

}

/// <summary>
/// Build the Player
/// </summary>
void Player::buildCurrent()
{
	auto render = std::make_unique<RenderItem>();
	renderer = render.get();
	renderer->World = getTransform();
	renderer->ObjCBIndex = game->getRenderItems().size();
	renderer->Mat = game->getMaterials()[mSprite].get();
	renderer->Geo = game->getGeometries()["boxGeo"].get();
	renderer->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	renderer->IndexCount = renderer->Geo->DrawArgs["box"].IndexCount;
	renderer->StartIndexLocation = renderer->Geo->DrawArgs["box"].StartIndexLocation;
	renderer->BaseVertexLocation = renderer->Geo->DrawArgs["box"].BaseVertexLocation;
	game->getRenderItems().push_back(std::move(render));
}
