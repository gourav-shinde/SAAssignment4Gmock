#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockButtonConsole.h"
#include "ElevatorKernal.h"


//mock

//tests
//at 6th floor moving to 4 
TEST(ElevatorTest, Test1) {
    MockButtonConsole mock_console;
    Elevator elevator(6, &mock_console);

    EXPECT_CALL(mock_console,RequestFloor(4));

    elevator.RequestFloor(4);
    EXPECT_EQ(elevator.CurrentFloor(), 6);
    EXPECT_EQ(elevator.Status(), Elevator::MovingDown);

    elevator.Update();
    EXPECT_EQ(elevator.CurrentFloor(), 5);
    EXPECT_EQ(elevator.Status(), Elevator::MovingDown);

    elevator.Update();
    EXPECT_EQ(elevator.CurrentFloor(), 4);
    EXPECT_EQ(elevator.Status(), Elevator::NotMoving);
}

//going down from 3 to 1 and 2 and 4 inputs were given 
TEST(ElevatorTest, TestDestinationInputs) {
    MockButtonConsole mock_console;
    Elevator elevator(3, &mock_console);

    EXPECT_CALL(mock_console,RequestFloor(2)).Times(1);
    EXPECT_CALL(mock_console,RequestFloor(4)).Times(1);
    EXPECT_CALL(mock_console, RequestFloor(6)).Times(1);

    elevator.RequestFloor(2);
    elevator.RequestFloor(4);
    elevator.RequestFloor(6);
    EXPECT_EQ(elevator.CurrentFloor(), 3);
    EXPECT_EQ(elevator.Status(), Elevator::MovingDown);

    elevator.Update();
    std::cout << elevator.current_floor << std::endl;
    std::cout << elevator.Status() << std::endl;
    EXPECT_EQ(elevator.CurrentFloor(), 2);
    EXPECT_EQ(elevator.Status(), Elevator::MovingUp);
    
    elevator.Update();
    EXPECT_EQ(elevator.CurrentFloor(), 3);
    EXPECT_EQ(elevator.Status(), Elevator::MovingUp);
    
    elevator.Update();
    EXPECT_EQ(elevator.CurrentFloor(), 4);
    EXPECT_EQ(elevator.Status(), Elevator::MovingUp);

    elevator.Update();
    EXPECT_EQ(elevator.CurrentFloor(), 5);
    EXPECT_EQ(elevator.Status(), Elevator::MovingUp);

    elevator.Update();
    EXPECT_EQ(elevator.CurrentFloor(), 6);
    EXPECT_EQ(elevator.Status(), Elevator::NotMoving);

}