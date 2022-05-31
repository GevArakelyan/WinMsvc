#pragma once
#include <vector>
#include <map>
#include <string>

typedef  std::vector<std::string> Words;
typedef  std::vector<unsigned int> Digits;

class StringToDigitsEncoder
{
	std::map<char, unsigned int> m_char_to_digit;

public:
	StringToDigitsEncoder();
	~StringToDigitsEncoder();
	Digits Encode(const std::string& str) const;
};

