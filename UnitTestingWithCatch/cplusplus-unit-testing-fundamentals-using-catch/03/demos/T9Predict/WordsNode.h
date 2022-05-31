#pragma once

class WordsNode
{
	Words m_words;
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
		m_words.push_back(word);
	}

	Words GetWords()const
	{
		return m_words;
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