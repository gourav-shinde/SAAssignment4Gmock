#pragma once
#include"DoorStatus.h"
#include"ButtonConsole.h"
class Elevator {
	Door door;
	ButtonConsole console= ButtonConsole(&door);
	int Max_floor = 10;
	int local_time = 0;
	int current_floor = 0;
	int nextFloor=-1;
	enum elevator_status { mov_down, mov_up, stationary };
	elevator_status statusE = mov_up;
public:
	void increamentFloor();
	void decreamentFloor();
	void destinationFloor();
	void process();
	void checkDoorStatus();
	void traverse();
};