#pragma once
#include "GameException.h"
class WrongTypedOptionException : public GameException
{
public:
	WrongTypedOptionException();
	WrongTypedOptionException(const char* message) : GameException(message), std::exception(message) {}
	~WrongTypedOptionException();
};

