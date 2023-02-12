#pragma once
#include<queue>
#include<set>
#include "DoorStatus.h"
class ButtonConsole {
	std::queue<int> destinationFloor;
	Door *door;
public:
	ButtonConsole(Door* ptr) :door(ptr) {};
	virtual void putFloor(std::set<int> nextFloor);
	virtual int getnextFloor();
	virtual int dequeue();
};