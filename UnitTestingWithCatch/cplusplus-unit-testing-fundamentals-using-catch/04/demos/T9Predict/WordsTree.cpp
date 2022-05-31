#include "WordsTree.h"
#include "WordsTreeException.h"

WordsTree::WordsTree() : m_root(new WordsNode())
{
	
}


WordsTree::~WordsTree()
{
	delete m_root;
}

void WordsTree::AddWord(const std::string& word, const Digits encoding)
{
	auto currNode = m_root;

	for (unsigned encodedChar : encoding)
	{
		auto child = currNode->GetChild(encodedChar);
		if (child == nullptr)
		{
			child = currNode->AddChild(encodedChar);
		}

		currNode = child;
	}
	
	if (currNode->HasWord(word))
	{
		throw WordsTreeException("Word already exist!");
	}

	currNode->AddWord(word);
}

Words WordsTree::GetWords(const Digits& encoding) const
{
	auto node = FindNode(encoding);

	if(node == nullptr)
	{
		return Words();
	}
	return node->GetWords();
}

WordsNode* WordsTree::FindNode(const Digits& encoding) const
{
	auto currNode = m_root;
	for (unsigned encodedChar : encoding)
	{
		currNode = currNode->GetChild(encodedChar);
		if (currNode == nullptr)
		{
			return nullptr;
		}
	}

	return currNode;
}