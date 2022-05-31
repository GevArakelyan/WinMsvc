#pragma once

#include <vector>
#include <string>

typedef  std::vector<std::string> Strings;
typedef  std::vector<unsigned int> Digits;

class WordsTree;

class Engine
{
	WordsTree& _wordsTree;

public:
	Engine(WordsTree& words) : _wordsTree(words)
	{
	};

	Strings GetWordsByDigits(const Digits& digits)const;
};
