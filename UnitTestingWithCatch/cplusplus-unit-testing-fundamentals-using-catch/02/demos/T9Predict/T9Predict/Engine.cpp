#include "Engine.h"

Strings Engine::GetWordsByDigits(const Digits& digits) const
{
	Strings result;
	if(digits.size() == 0)
	{
		return result;
	}
	
	result.push_back("");

	return result;
}
