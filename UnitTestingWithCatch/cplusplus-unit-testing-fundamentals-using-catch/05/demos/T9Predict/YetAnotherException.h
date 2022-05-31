#pragma once
#include <stdexcept>

class YetAnotherException : public std::runtime_error {
public:
	YetAnotherException(const std::string& _Message)
		: runtime_error(_Message)
	{
	}

	YetAnotherException(const char* _Message)
		: runtime_error(_Message)
	{
	}
};