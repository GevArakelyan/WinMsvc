#pragma once
#include <stdexcept>

class WordsTreeException : public std::runtime_error
{
public:
	WordsTreeException(const std::string& _Message)
		: runtime_error(_Message)
	{
	}

	WordsTreeException(const char* _Message)
		: runtime_error(_Message)
	{
	}
};
