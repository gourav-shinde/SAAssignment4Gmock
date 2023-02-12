#include "DoorStatus.h"



void Door::closeDoor() {
	current_status = closed;
}
void Door::openDoor() {
	current_status = open;
}
int Door::getDoorStatus() {
	return current_status;
}
