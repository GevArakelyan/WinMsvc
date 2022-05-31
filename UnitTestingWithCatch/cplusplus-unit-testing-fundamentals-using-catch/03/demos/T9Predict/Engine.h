#pragma once

#include "StringToDigitsEncoder.h"
#include "WordsTree.h"

class Engine
{
	WordsTree m_wordsTree;
	StringToDigitsEncoder m_encoder;

public:
	Engine(){}

	void LearnNewWords(Words words);

	Words GetWordsByDigits(const Digits& digits)const;
};
