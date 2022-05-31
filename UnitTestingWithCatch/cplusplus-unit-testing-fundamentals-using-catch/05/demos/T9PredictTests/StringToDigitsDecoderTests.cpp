#include "Catch.hpp"

#include "../T9Predict/StringToDigitsEncoder.h"
#include <tuple>
#include "StringsToValueGenerator.h"

class StringToDigitEncoderTests
{
protected:
	StringToDigitsEncoder encoder;

	void EncodeAndCheck(const std::vector<std::string>& strings, unsigned expectedDigit) const
	{
		for (auto str : strings)
		{
			auto result = encoder.Encode(str);

			CHECK(result == Digits({ expectedDigit }));
		}
	}
};

TEST_CASE_METHOD(StringToDigitEncoderTests, "Encode single uppercase letter --> return correct digit", "[Single Digit]")
{
	EncodeAndCheck({ "A", "B", "C" }, 2);
	EncodeAndCheck({ "D", "E", "F" }, 3);
	EncodeAndCheck({ "G", "H", "I" }, 4);
	EncodeAndCheck({ "J", "K", "L" }, 5);
	EncodeAndCheck({ "M", "N", "O" }, 6);
	EncodeAndCheck({ "P", "Q", "R", "S" }, 7);
	EncodeAndCheck({ "T", "U", "V" }, 8);
	EncodeAndCheck({ "W", "X", "Y", "Z" }, 9);
}

TEST_CASE("Encode single letter --> return correct digit", "[Single Digit]") 
{
	StringToDigitsEncoder encoder;

	auto pair = GENERATE(string2value({ {{"a", "b", "c"}, 2 }, {{"d", "e","f"},3} }));
	
	std::string value = pair.first;
	
	CAPTURE(value);

	REQUIRE(encoder.Encode(value) == Digits({ pair.second }));
}

TEST_CASE("Encode single lowercase letter --> return correct digit", "[Single Digit]")
{
	StringToDigitsEncoder encoder;

	CHECK(encoder.Encode("a") == Digits({ 2 }));
	CHECK(encoder.Encode("b") == Digits({ 2 }));
	CHECK(encoder.Encode("c") == Digits({ 2 }));

	CHECK(encoder.Encode("d") == Digits({ 3 }));
	CHECK(encoder.Encode("e") == Digits({ 3 }));
	CHECK(encoder.Encode("f") == Digits({ 3 }));

	CHECK(encoder.Encode("g") == Digits({ 4 }));
	CHECK(encoder.Encode("h") == Digits({ 4 }));
	CHECK(encoder.Encode("i") == Digits({ 4 }));

	CHECK(encoder.Encode("j") == Digits({ 5 }));
	CHECK(encoder.Encode("k") == Digits({ 5 }));
	CHECK(encoder.Encode("l") == Digits({ 5 }));

	CHECK(encoder.Encode("m") == Digits({ 6 }));
	CHECK(encoder.Encode("n") == Digits({ 6 }));
	CHECK(encoder.Encode("o") == Digits({ 6 }));

	CHECK(encoder.Encode("p") == Digits({ 7 }));
	CHECK(encoder.Encode("q") == Digits({ 7 }));
	CHECK(encoder.Encode("r") == Digits({ 7 }));
	CHECK(encoder.Encode("s") == Digits({ 7 }));

	CHECK(encoder.Encode("t") == Digits({ 8 }));
	CHECK(encoder.Encode("u") == Digits({ 8 }));
	CHECK(encoder.Encode("v") == Digits({ 8 }));

	CHECK(encoder.Encode("w") == Digits({ 9 }));
	CHECK(encoder.Encode("x") == Digits({ 9 }));
	CHECK(encoder.Encode("y") == Digits({ 9 }));
	CHECK(encoder.Encode("z") == Digits({ 9 }));
}

TEST_CASE("Given a string Hello return 43556", "[End2End][Regression]")
{
	StringToDigitsEncoder encoder;

	auto result = encoder.Encode("Hello");

	Digits expected = { 4,3,5,5,6 };

	REQUIRE(result == expected);
}