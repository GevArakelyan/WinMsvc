#include "../T9Predict/WordsTree.h"

#include "Catch.hpp"
#include "../T9Predict/YetAnotherException.h"
#include "../T9Predict/WordsTreeException.h"
using namespace std;

TEST_CASE("If no words exist GetWords returns empty collection", "[Init]")
{
	WordsTree tree;

	REQUIRE(tree.GetWords(Digits{ 1,2,3,4 }).size() == 0);
}

TEST_CASE("Find one letter word which exist in tree", "[Search]")
{
	WordsTree tree;

	tree.AddWord("a", { 2 });

	auto result = tree.GetWords(Digits{ 2 });

	auto expected = vector<string>({ "a" });

	REQUIRE(result == expected);
}

TEST_CASE("Find two one letter words which exist in tree", "[Search]")
{
	WordsTree tree;

	tree.AddWord("a", { 2 });
	tree.AddWord("b", { 2 });

	auto result = tree.GetWords(Digits{ 2 });

	REQUIRE(result.size() == 2);
	REQUIRE(std::find(result.begin(), result.end(), "a") != result.end());
	REQUIRE(std::find(result.begin(), result.end(), "b") != result.end());
}

TEST_CASE("Find two letter word which exist in tree", "[Search]")
{
	WordsTree tree;

	tree.AddWord("ad", { 2, 3 });

	auto result = tree.GetWords(Digits{ 2, 3 });
	REQUIRE(result.size() == 1);
	REQUIRE(result[0] == "ad");
}

TEST_CASE("Find word when tree has different encoded word begins with same letter", "[Search]")
{
	WordsTree tree;

	tree.AddWord("ab", { 2, 2 });
	tree.AddWord("ad", { 2, 3 });

	CHECK(tree.GetWords(Digits{ 2, 3 }) == vector<string>({ "ad" }));
	CHECK(tree.GetWords(Digits{ 2, 2 }) == vector<string>({ "ab" }));
}



TEST_CASE("Adding the same word twice throws an exception")
{
	WordsTree tree;

	tree.AddWord("ab", { 2, 2 });

	REQUIRE_THROWS_AS(tree.AddWord("ab", { 2, 2 }), WordsTreeException);
}