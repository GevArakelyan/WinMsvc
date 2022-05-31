#include "Word.h"

using namespace std;

Word::Word(string text) : m_text(text), m_frequency(0)
{
}


Word::~Word()
{
}

const string& Word::GetText() const
{
	return m_text;
}

const unsigned& Word::GetFrequency() const
{
	return m_frequency;
}
