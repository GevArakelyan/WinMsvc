#pragma once
#include <string>

class WordsTree
{
public:
	WordsTree();
	~WordsTree();

	void AddWord(const std::string& word);
	bool DoesWordExist(const std::string word)const;
};

