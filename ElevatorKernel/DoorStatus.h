#pragma once
class Door {
public:
	enum status { open, closed };
	virtual void closeDoor();
	virtual void openDoor();
	virtual int getDoorStatus();
private:
	status current_status = open;
};