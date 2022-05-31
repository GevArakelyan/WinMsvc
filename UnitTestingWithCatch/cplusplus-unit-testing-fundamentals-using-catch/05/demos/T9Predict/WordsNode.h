#pragma once
#include <unordered_set>

class WordsNode
{
	std::unordered_set<std::string> m_words;
	WordsNode* m_children[10];

public:
	~WordsNode()
	{
		for (auto child : m_children)
		{
			delete child;
		}
	}

	void AddWord(const std::string& word)
	{
		m_words.insert(word);
	}

	bool HasWord(const std::string& word)
	{
		return m_words.find(word) != m_words.end();
	}

	Words GetWords()const
	{
		return Words(m_words.begin(), m_words.end());
	}

	WordsNode* GetChild(unsigned encoding)const
	{
		return m_children[encoding];
	}

	WordsNode* AddChild(unsigned encoding)
	{
		m_children[encoding] = new WordsNode();

		return m_children[encoding];
	}

	void DeleteAllChildrens()
	{
		for (auto child : m_children)
		{
			child->DeleteAllChildrens();
			delete child;
		}
	}
};
