//#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_all.hpp"

// [.] means hidden by default.
TEST_CASE("hidden test", "[.][a]")
{

}
// [.][integration] is same as [.integration]
TEST_CASE("hidden test 2", "[.integration]")
{

}
// below test will be excluded when running with
// -e or --nothrow
TEST_CASE("test exceptions", "[!throws]")
{
	//REQUIRE_THROWS(1 == 1);
	//commented above line so it won't show failing
}
 // Reverse failing logic(pass if fail)
TEST_CASE("test exceptions", "[!shouldfail]")
{
	REQUIRE_THROWS(1 == 1);
	//throw std::runtime_error("test");
}

TEST_CASE("test exceptions", "[!mayfail]")
{
	//REQUIRE_THROWS(1 == 1);
	//throw std::runtime_error("test");
}

// to run only test from filename.cpp
// -# [#fileName]


TEST_CASE("a test", "[a]")
{
	//REQUIRE_THROWS(1 == 1);
	//throw std::runtime_error("test");
}
TEST_CASE("b test", "[b]")
{
	//REQUIRE_THROWS(1 == 1);
	//throw std::runtime_error("test");
}
TEST_CASE("c test", "[c]")
{
	REQUIRE_THROWS(1 == 1);
	//throw std::runtime_error("test");
}

// to combine tests.
CATCH_REGISTER_TAG_ALIAS("[@abc]", "[a], [b] ~[c]")
// t.exe [@abc]
namespace {
	std::vector<int> vec1, vec2;
	int val = 9;

}
using namespace Catch::Matchers;

TEST_CASE("d test", "[d]")
{
	REQUIRE_THAT(vec1, Contains(val));
	REQUIRE_THAT(vec1, VectorContains(1));
	REQUIRE_THAT(vec1, Equals(vec2));
	REQUIRE_THAT(vec1, UnorderedEquals(vec2));
	REQUIRE_THAT(vec1, Approx(vec2));


	REQUIRE_THAT(val, WithinAbs(1.0, .5));
	REQUIRE_THAT(val, WithinULP(1.0, 2));
	REQUIRE_THAT(val, WithinRel(1.0, 0.0005));





	REQUIRE_THROWS(1 == 1);
	//throw std::runtime_error("test");
}
void fun() {
	throw std::runtime_error("runtime error");
}

TEST_CASE("Exception related")
{
	REQUIRE_THROWS_WITH(fun(), "runtime");

	//REQUIRE_THROWS_WITH(fun(), Contains("Runtime"));
}


TEST_CASE("Require that") {
	REQUIRE_THAT(val, Predicate<int>(
		[](int i) { return i == 0;  },
		"Number must be 0"
		));
}

// CATCH_REGISTER_ENUM(MyEnum, MyEnum::One,MyEnum::Two);
struct MyType : public std::exception {
	std::string message() {
		return "MyType exception";
	}
};
//
//CATCH_TRANSLATE_EXCEPTION(MyType& ex)
//{
//	return ex.message();
//}

TEST_CASE("Generators") {
	GENERATE(1, 2, 3);
	GENERATE(values({ 1,2,3 }));
	GENERATE(as<std::string>{}, "a", "b", "c");
	//GENERATE(repeat(2, range({ 1,100 })));
	GENERATE(take(10, random(1, 100)));

	GENERATE(filter([](int val) { return val % 2 == 0; },
		range(1, 100)));
	GENERATE(map([](int val) { return std::to_string(val); },
		range(1, 100)));

}


/*

class MyGen : public IGenerator<int> {
	int const& get() const override { ... };
	bool next() override { ... }
};
GeneratorWrapper<int> myGen(a1,a2,...) {
	return GeneratorWrapper<int>(
		unique_ptr<IGenerator<int>>(new MyGen(a1,a2,...));
}
*/

// Type parametrized tests

TEMPLATE_TEST_CASE("TEMPLATE TEST", "[Tag1]", int, std::string)
{
	std::vector<TestType> v(5);
	//...
}
TEMPLATE_PRODUCT_TEST_CASE("name",
	"[tag1]...",
	(std::vector, std::list), (int, float))
{

}