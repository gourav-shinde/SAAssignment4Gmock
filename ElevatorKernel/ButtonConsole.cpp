#pragma once
#include<queue>
#include"ButtonConsole.h"
#include<iostream>

void ButtonConsole::putFloor(std::set<int> nextFloor) {
	if (door->getDoorStatus() == door->closed) {
		for (auto itr : nextFloor) {
			destinationFloor.push(itr);
		}
	}
	else {
		std::cout << "Door Open, close door and try again!";
	}
}

int ButtonConsole::getnextFloor() {
	return dequeue();
}

int ButtonConsole::dequeue() {
	if (destinationFloor.empty()) {
		return -1;
	}
	int temp = destinationFloor.front();
	destinationFloor.pop();
	return temp;
}
