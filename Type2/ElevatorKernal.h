#pragma once
#include"ButtonConsole.h"
#include<queue>


class Elevator {
public:
    enum ElevatorStatus { MovingUp, MovingDown, NotMoving };
    ButtonConsole *console;
    int current_floor;
    ElevatorStatus status = NotMoving;
    std::priority_queue<int, std::vector<int>, std::greater<int>> destinations;
    //constructor
    Elevator(int _current_floor, ButtonConsole *_console);
    void Update();
    int CurrentFloor();
    ElevatorStatus Status();
    void UpdateStatus();
    void RequestFloor(int floor);

};