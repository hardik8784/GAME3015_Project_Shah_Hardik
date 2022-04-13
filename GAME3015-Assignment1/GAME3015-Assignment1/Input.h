#pragma once

#include <vector>
#include <string>


struct Listener
{
	char bindChar;
	int bindInt;
	std::string name;
	bool active;
};

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