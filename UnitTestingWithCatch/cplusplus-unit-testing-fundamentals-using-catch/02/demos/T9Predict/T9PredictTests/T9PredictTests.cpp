#include "stdafx.h"

#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "../T9Predict/WordsTree.h"
#include "../T9Predict/Engine.h"

TEST_CASE("Called with empty digit list --> returns no results")
{
	WordsTree emptyTree;
	Engine t9engine(emptyTree);

	Digits digits;

	auto result = t9engine.GetWordsByDigits(digits);

	REQUIRE(result.size() == 0);
}

TEST_CASE("When called with 43556 and known word then return hello")
{
	WordsTree knownWords;
	knownWords.AddWord("hello");

	Engine t9engine(knownWords);

	Digits digits = { 4,3,5,5,6 };

	auto result = t9engine.GetWordsByDigits(digits);

	REQUIRE(result[0] == "hello");
}