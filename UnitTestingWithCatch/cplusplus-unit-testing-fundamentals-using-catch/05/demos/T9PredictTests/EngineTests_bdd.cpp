#include "Catch.hpp"

#include "../T9Predict/Engine.h"

SCENARIO("If words are known entering their encoding will return all words")
{
	GIVEN("'hello' is a known word")
	{
		Engine t9engine;
		t9engine.LearnNewWords({ "hello" });

		WHEN("called with the right encoding")
		{
			Digits digits = { 4,3,5,5,6 };

			auto result = t9engine.GetWordsByDigits(digits);

			THEN("return 'hello'")
			{
				REQUIRE(result.size() == 1);
				REQUIRE(result[0] == "hello");
			}
		}
	}
}
