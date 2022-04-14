#include "StateMachine.h"

StateMachine::StateMachine(Game* game)
{
	mGame = game;
	titleState = new TitleState(game);
	menuState = new MenuState(game);
	controlsState = new ControlsState(game);
	gameState = new GameState(game);

	states.push_back(titleState);
	states.push_back(menuState);
	states.push_back(controlsState);
	states.push_back(gameState);

	enterKey.name = "Enter";
	enterKey.bindInt = 0x0D;
	enterKey.active = true;

	backspaceKey.name = "BackSpace";
	backspaceKey.bindInt = 0x08;
	backspaceKey.active = true;

	pause.name = "Pause";
	pause.bindInt = 0x50;
	pause.active = true;

}

/// <summary>
/// drawing the states
/// </summary>
/// <param name="gt"></param>
void StateMachine::draw(const GameTimer& gt)
{
	for (int i = 0; i < states.size(); i++)
	{
		states[i]->draw(gt);
	}
}

/// <summary>
/// Changing the states as per the input
/// </summary>
/// <param name="gt"></param>
void StateMachine::input(const GameTimer& gt)
{
	for (int i = 0; i < states.size(); i++)
	{
		if (states[i]->mOrder == 0)
		{
			states[i]->getInputs(gt);
			if (states[i] == titleState)
			{
				if (listeners.CheckTrigger(enterKey))
				{
					SetState(menuState);
				}
			}
			else if (states[i] == menuState)
			{
				if (listeners.CheckTrigger(enterKey))
				{
					if (menuState->option == 0)
					{
						SetState(gameState);
					}
					if (menuState->option == 1)
					{
						SetState(controlsState);
					}
				}
			}
			else if (states[i] == controlsState)
			{
				if (listeners.CheckTrigger(backspaceKey))
				{
					SetState(menuState);
				}
			}
			else if (states[i] == gameState)
			{
				if (listeners.CheckTrigger(pause))
				{
					if (gameState->isPaused)
					{
						gameState->isPaused = false;
					}
					else
					{
						gameState->isPaused = true;
					}
				}
				if (listeners.CheckTrigger(backspaceKey))
				{
					if (gameState->isPaused)
					{
						gameState->isPaused = false;
						SetState(menuState);
					}
				}
			}
		}
	}
}

/// <summary>
/// Update the state
/// </summary>
/// <param name="gt"></param>
void StateMachine::update(const GameTimer& gt)
{
	for (int i = 0; i < states.size(); i++)
	{
		states[i]->update(gt);
	}
}

/// <summary>
/// Setting the state 
/// </summary>
/// <param name="s"></param>
void StateMachine::SetState(State* s)
{
	for (int i = 0; i < states.size(); i++)
	{
		if (states[i] == s)
		{
			states[i]->mOrder = 0;
		}
		else
		{
			states[i]->mOrder = 10;
		}
	}
}

/// <summary>
/// Loading the state
/// </summary>
void StateMachine::load()
{
	for (int i = 0; i < states.size(); i++)
	{
		states[i]->mOrder = i;
		states[i]->load();
	}
}
