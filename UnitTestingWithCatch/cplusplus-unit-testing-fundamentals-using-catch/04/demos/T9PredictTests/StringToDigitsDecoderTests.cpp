#include "Catch.hpp"

#include "../T9Predict/StringToDigitsEncoder.h"

TEST_CASE("Encode single uppercase letter --> return correct digit", "[Single Digit]")
{
	StringToDigitsEncoder encoder;

	CHECK(encoder.Encode("A") == Digits({ 2 }));
	CHECK(encoder.Encode("B") == Digits({ 2 }));
	CHECK(encoder.Encode("C") == Digits({ 2 }));

	CHECK(encoder.Encode("D") == Digits({ 3 }));
	CHECK(encoder.Encode("E") == Digits({ 3 }));
	CHECK(encoder.Encode("F") == Digits({ 3 }));

	CHECK(encoder.Encode("G") == Digits({ 4 }));
	CHECK(encoder.Encode("H") == Digits({ 4 }));
	CHECK(encoder.Encode("I") == Digits({ 4 }));

	CHECK(encoder.Encode("J") == Digits({ 5 }));
	CHECK(encoder.Encode("K") == Digits({ 5 }));
	CHECK(encoder.Encode("L") == Digits({ 5 }));

	CHECK(encoder.Encode("M") == Digits({ 6 }));
	CHECK(encoder.Encode("N") == Digits({ 6 }));
	CHECK(encoder.Encode("O") == Digits({ 6 }));
	
	CHECK(encoder.Encode("P") == Digits({ 7 }));
	CHECK(encoder.Encode("Q") == Digits({ 7 }));
	CHECK(encoder.Encode("R") == Digits({ 7 }));
	CHECK(encoder.Encode("S") == Digits({ 7 }));

	CHECK(encoder.Encode("T") == Digits({ 8 }));
	CHECK(encoder.Encode("U") == Digits({ 8 }));
	CHECK(encoder.Encode("V") == Digits({ 8 }));

	CHECK(encoder.Encode("W") == Digits({ 9 }));
	CHECK(encoder.Encode("X") == Digits({ 9 }));
	CHECK(encoder.Encode("Y") == Digits({ 9 }));
	CHECK(encoder.Encode("Z") == Digits({ 9 }));
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