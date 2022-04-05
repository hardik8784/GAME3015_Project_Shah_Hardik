#pragma once
#include "Command.h"
#include <map>

class CommandQueue;

class Player
{
public:
	Player();
	void	handleEvent(CommandQueue& commands);
	void	handleRealtimeInput(CommandQueue& commands);
	
	enum Action
	{
		MoveUp,
		MoveDown,
		MoveLeft,
		MoveRight,
		Count
	};

	void	assignKey(Action action, char key);
	char	getAssignedKey(Action action) const;


private:
	void	initActions();
	static bool	isRealtimeAction(Action action);

private:
	std::map<char, Action>					mKeyBinding;

	std::map<Action, Command>				mActionBinding;

	std::map<char, bool>					mKeyFlag;

};