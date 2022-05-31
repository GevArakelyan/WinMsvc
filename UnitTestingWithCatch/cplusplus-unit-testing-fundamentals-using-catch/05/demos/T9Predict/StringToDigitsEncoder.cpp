#include "StringToDigitsEncoder.h"
#include <locale>

using namespace std;

StringToDigitsEncoder::StringToDigitsEncoder()
{
	m_char_to_digit = {
		{ make_pair('A', 2) }, { make_pair('B', 2) }, { make_pair('C', 2) },
		{ make_pair('D', 3) }, { make_pair('E', 3) }, { make_pair('F', 3) },
		{ make_pair('G', 4) }, { make_pair('H', 4) }, { make_pair('I', 4) },
		{ make_pair('J', 5) }, { make_pair('K', 5) }, { make_pair('L', 5) },
		{ make_pair('M', 6) }, { make_pair('N', 6) }, { make_pair('O', 6) },
		{ make_pair('P', 7) }, { make_pair('Q', 7) }, { make_pair('R', 7) }, { make_pair('S', 7) },
		{ make_pair('T', 8) }, { make_pair('U', 8) }, { make_pair('V', 8) },
		{ make_pair('W', 9) }, { make_pair('X', 9) }, { make_pair('Y', 9) }, { make_pair('Z', 9) }
	};
}


StringToDigitsEncoder::~StringToDigitsEncoder()
{
}

Digits StringToDigitsEncoder::Encode(const string& str) const
{
	Digits result;

	for (auto c : str)
	{
		char upper = toupper(c);

		const unsigned encoded = m_char_to_digit.at(upper);

		result.push_back(encoded);
	}

	return result;
}
