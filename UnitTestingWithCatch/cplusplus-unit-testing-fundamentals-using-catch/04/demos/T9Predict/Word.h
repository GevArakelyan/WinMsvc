#pragma once

#include <string>

class Word
{
	std::string m_text;
	unsigned m_frequency;
public:
	Word(std::string text);
	~Word();


	const std::string& GetText() const;
	const unsigned& GetFrequency() const;
};


