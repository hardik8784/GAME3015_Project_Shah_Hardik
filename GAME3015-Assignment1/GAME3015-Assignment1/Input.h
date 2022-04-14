#pragma once

#include <vector>
#include <string>

/// <summary>
/// Created the struct of Listener
/// </summary>
struct Listener
{
	char bindChar;
	int bindInt;
	std::string name;
	bool active;
};

/// <summary>
/// Class ListernerManager which checks the inputs from the player
/// </summary>
class ListenerManager
{
public:

	bool CheckListener(Listener ev);
	bool CheckTrigger(Listener ev);

	ListenerManager();
	~ListenerManager();

	void AddListener(Listener ev);
	Listener PrevEvent();
	Listener CurrentEvent();

private:

	std::vector<Listener> listeners;
	std::vector<Listener> eventList;
	Listener none;

};