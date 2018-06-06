#pragma once
#include "GameException.h"
class WrongFileFormatException : public GameException
{
public:
	WrongFileFormatException();
	WrongFileFormatException(const char* message) : GameException(message), std::exception(message) {}
	~WrongFileFormatException();
};

