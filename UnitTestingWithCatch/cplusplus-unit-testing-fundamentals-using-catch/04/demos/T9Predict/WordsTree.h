#pragma once
#include "StringToDigitsEncoder.h"
#include "WordsNode.h"

#define  NUMBER_OF_ALPHABET_LETTERS 26


class WordsTree
{
	WordsNode* m_root;

	WordsNode* FindNode(const Digits& encoding)const;

public:
	WordsTree();
	~WordsTree();

	void AddWord(const std::string& word, const Digits encoding);
	Words GetWords(const Digits& encoding)const;
};