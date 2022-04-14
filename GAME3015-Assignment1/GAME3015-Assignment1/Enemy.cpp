#include "Enemy.h"
#include "Game.hpp"

/// <summary>
/// Constructor for Enemy
/// </summary>
/// <param name="game"></param>
/// <param name="name"></param>
Enemy::Enemy(Game* game, std::string name) : Entity(game, name)
{
	mSprite = "Raptor";
	mName = name;
}

/// <summary>
/// Building the Enemy
/// </summary>
void Enemy::buildCurrent()
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

void Enemy::drawCurrent() const
{

}