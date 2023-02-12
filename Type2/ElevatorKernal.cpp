#pragma once
#include"ElevatorKernal.h"
//abstract


Elevator::Elevator(int _current_floor, ButtonConsole *_console) {
    current_floor = _current_floor;
    console = _console;
}

void Elevator::RequestFloor(int floor) {
    //destinations.push(console->requestedFloor);
    console->RequestFloor(floor);
    destinations.push(floor);
    UpdateStatus();

}

void  Elevator::Update() {
    
    if (status == ElevatorStatus::NotMoving) {
        return;
    }
    if (status == ElevatorStatus::MovingUp) {
        current_floor++;
    }
    if(status == ElevatorStatus::MovingDown) {
        current_floor--;
    }
    if (current_floor == destinations.top()) {
        destinations.pop(); 
    }
    UpdateStatus();
    
}

int  Elevator::CurrentFloor() {
    return current_floor;
}
Elevator::ElevatorStatus  Elevator::Status() {
    return status;
}


void  Elevator::UpdateStatus() {
    if (destinations.empty()) {
        status = ElevatorStatus::NotMoving;
    }
    else if (destinations.top() > current_floor) {
        status = ElevatorStatus::MovingUp;
    }
    else {
        status = ElevatorStatus::MovingDown;
    }
}


