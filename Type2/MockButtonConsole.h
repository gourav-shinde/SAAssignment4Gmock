#pragma once
#include"ButtonConsole.h"
#include "gmock/gmock.h"

class MockButtonConsole : public ButtonConsole {
public:
    MOCK_METHOD(void, RequestFloor, (int floor), (override));
};
