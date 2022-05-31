#include "Engine.h"

void Engine::LearnNewWords(Words words)
{
	for(auto word : words)
	{
		auto encoded = m_encoder.Encode(word);
		m_wordsTree.AddWord(word, encoded);
	}
}

Words Engine::GetWordsByDigits(const Digits& digits) const
{
	if(digits.size() == 0)
	{
		return Words();
	}
	
	return m_wordsTree.GetWords(digits);
}
