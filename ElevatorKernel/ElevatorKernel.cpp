// ElevatorKernel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ElevatorKernel.h"


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


//TODO
//should not be able to get input when door is open
//should not be in moving status when door is open


void Elevator::increamentFloor() {
	++current_floor;
	++local_time;
}

void Elevator::decreamentFloor() {
	--current_floor;
	++local_time;
}

void Elevator::destinationFloor() {
	nextFloor = console.getnextFloor();
}

void Elevator::checkDoorStatus() {

}
void Elevator::traverse() {
	if (current_floor > nextFloor) {
		statusE = mov_down;
		while (current_floor != nextFloor) {
			decreamentFloor();
		}
	}
	else {
		statusE = mov_up;
		while (current_floor != nextFloor) {
			increamentFloor();
		}
	}
}


void Elevator::process(){
	
	while (true) {
		door.openDoor();
		console.putFloor(std::set<int> {3, 5, 7, 9, 1, 3, 4, 5, 6});
		door.closeDoor();
		destinationFloor();
		traverse();
	}
}