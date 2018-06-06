#pragma once
#include <exception>
class GameException : public virtual std::exception
{
public:
	GameException();
	GameException(const char* message) : std::exception(message) {}
	~GameException();
};

