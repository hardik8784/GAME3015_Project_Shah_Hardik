#include "State.h"
#include "Player.h"
#include "Enemy.h"

class GameState : public State
{
public:

	GameState(Game* window);

	bool isPaused;

	void getInputs(const GameTimer& gt) override;
	void draw(const GameTimer& gt) override;
	void update(const GameTimer& gt) override;
	void load() override;

private:
	
	SpriteNode* mBackground;
	SpriteNode* mPause;
	Player* mPlayer;
	Enemy* mEnemy1;
	Enemy* mEnemy2;
};