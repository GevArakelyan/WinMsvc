#include "Catch.hpp"

#include "../T9Predict/StringToDigitsEncoder.h"

TEST_CASE("Encode single uppercase letter --> return correct digit", "[Single Digit]")
{
	StringToDigitsEncoder encoder;

	REQUIRE(encoder.Encode("A") == Digits({ 2 }));
	REQUIRE(encoder.Encode("B") == Digits({ 2 }));
	REQUIRE(encoder.Encode("C") == Digits({ 2 }));

	REQUIRE(encoder.Encode("D") == Digits({ 3 }));
	REQUIRE(encoder.Encode("E") == Digits({ 3 }));
	REQUIRE(encoder.Encode("F") == Digits({ 3 }));

	REQUIRE(encoder.Encode("G") == Digits({ 4 }));
	REQUIRE(encoder.Encode("H") == Digits({ 4 }));
	REQUIRE(encoder.Encode("I") == Digits({ 4 }));

	REQUIRE(encoder.Encode("J") == Digits({ 5 }));
	REQUIRE(encoder.Encode("K") == Digits({ 5 }));
	REQUIRE(encoder.Encode("L") == Digits({ 5 }));

	REQUIRE(encoder.Encode("M") == Digits({ 6 }));
	REQUIRE(encoder.Encode("N") == Digits({ 6 }));
	REQUIRE(encoder.Encode("O") == Digits({ 6 }));
	
	REQUIRE(encoder.Encode("P") == Digits({ 7 }));
	REQUIRE(encoder.Encode("Q") == Digits({ 7 }));
	REQUIRE(encoder.Encode("R") == Digits({ 7 }));
	REQUIRE(encoder.Encode("S") == Digits({ 7 }));

	REQUIRE(encoder.Encode("T") == Digits({ 8 }));
	REQUIRE(encoder.Encode("U") == Digits({ 8 }));
	REQUIRE(encoder.Encode("V") == Digits({ 8 }));

	REQUIRE(encoder.Encode("W") == Digits({ 9 }));
	REQUIRE(encoder.Encode("X") == Digits({ 9 }));
	REQUIRE(encoder.Encode("Y") == Digits({ 9 }));
	REQUIRE(encoder.Encode("Z") == Digits({ 9 }));
}

TEST_CASE("Encode single lowercase letter --> return correct digit", "[Single Digit]")
{
	StringToDigitsEncoder encoder;

	REQUIRE(encoder.Encode("a") == Digits({ 2 }));
	REQUIRE(encoder.Encode("b") == Digits({ 2 }));
	REQUIRE(encoder.Encode("c") == Digits({ 2 }));

	REQUIRE(encoder.Encode("d") == Digits({ 3 }));
	REQUIRE(encoder.Encode("e") == Digits({ 3 }));
	REQUIRE(encoder.Encode("f") == Digits({ 3 }));

	REQUIRE(encoder.Encode("g") == Digits({ 4 }));
	REQUIRE(encoder.Encode("h") == Digits({ 4 }));
	REQUIRE(encoder.Encode("i") == Digits({ 4 }));

	REQUIRE(encoder.Encode("j") == Digits({ 5 }));
	REQUIRE(encoder.Encode("k") == Digits({ 5 }));
	REQUIRE(encoder.Encode("l") == Digits({ 5 }));

	REQUIRE(encoder.Encode("m") == Digits({ 6 }));
	REQUIRE(encoder.Encode("n") == Digits({ 6 }));
	REQUIRE(encoder.Encode("o") == Digits({ 6 }));

	REQUIRE(encoder.Encode("p") == Digits({ 7 }));
	REQUIRE(encoder.Encode("q") == Digits({ 7 }));
	REQUIRE(encoder.Encode("r") == Digits({ 7 }));
	REQUIRE(encoder.Encode("s") == Digits({ 7 }));

	REQUIRE(encoder.Encode("t") == Digits({ 8 }));
	REQUIRE(encoder.Encode("u") == Digits({ 8 }));
	REQUIRE(encoder.Encode("v") == Digits({ 8 }));

	REQUIRE(encoder.Encode("w") == Digits({ 9 }));
	REQUIRE(encoder.Encode("x") == Digits({ 9 }));
	REQUIRE(encoder.Encode("y") == Digits({ 9 }));
	REQUIRE(encoder.Encode("z") == Digits({ 9 }));
}

TEST_CASE("Given a string Hello return 43556", "[End2End][Regression]")
{
	StringToDigitsEncoder encoder;

	auto result = encoder.Encode("Hello");

	Digits expected = { 4,3,5,5,6 };
	
	REQUIRE(result == expected);
}