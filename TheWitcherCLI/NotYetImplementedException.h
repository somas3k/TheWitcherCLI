#pragma once
#include "GameException.h"
class NotYetImplementedException : public GameException
{
public:
	NotYetImplementedException();
	NotYetImplementedException(const char* message) : GameException(message), std::exception(message) {}
	~NotYetImplementedException();
};

