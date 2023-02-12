#pragma once
class ButtonConsole{
public:
    int currentFloor,requestedFloor;
    virtual void RequestFloor(int floor);
};
