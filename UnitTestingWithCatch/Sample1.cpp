#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_all.hpp"


/*
	 REQUIRE_THAT will abort the test
	 CHECK_THAT will continue the rest of the test after fail.
 */

TEST_CASE("FIRST TEST")
{
	
}

int fun(int input)
{
	if (input >= 1) return fun(input - 1) + fun(input - 2);
	else return 1;
}

//TEST_CASE("Parametrized benchmark")
//{
//	auto input = GENERATE(10, 15);
//	BENCHMARK("fun " + std::to_string(input))
//	{
//		return fun(input);
//	};
//}

inline auto FunString()
{
	return std::string_view("fun, gun");
}
using namespace Catch::Matchers;

TEST_CASE("String matchers", "[matchers]")
{
	//CHECK_THAT(FunString(), Catch::Matchers::Contains("fun"));
	/*CHECK_THAT(FunString(), Contains("gun"));

	CHECK_THAT(FunString(), StartsWith("fun"));
	CHECK_THAT(FunString(), EndsWith("gun"));*/


	/*CHECK_THAT(FunString(),
		(Contains("fun") || Contains("gun")));*/
}

std::vector<int> v{ 1,2,3 };
TEST_CASE("Contains (element)")
{
	SECTION("VectorContains)")
	{
		CHECK_THAT(v, VectorContains(1));
	}
	SECTION("Contains)")
	{
		CHECK_THAT(v, Contains(1));
	}
}
//------------- Matcher example
struct SpecialException {
	int m_expected;
};
class ExMatcher : public Catch::Matchers::MatcherBase<SpecialException>
{
	int m_expected;
public:
	explicit ExMatcher(int expected) : m_expected(expected) {}

	bool match(SpecialException const& ex) const override
	{
		return m_expected == ex.m_expected;
	}

	std::string describe() const override
	{
		std::ostringstream ss;
		ss << "SpecialException with expected value " << m_expected;
		return ss.str();
	}
};
void throws(int i)
{
	throw SpecialException{ i };  // NOLINT(hicpp-exception-baseclass)
}

TEST_CASE("Exception matchers that succeed", "[matchers][exceptions][!throws]")
{
	CHECK_THROWS_MATCHES(throws(1), SpecialException, ExMatcher{ 1 });
	REQUIRE_THROWS_MATCHES(throws(2), SpecialException, ExMatcher{ 2 });

}
// Generators
TEST_CASE("10*10 ints")
{
	auto x = GENERATE(range(1, 11));
	auto y = GENERATE(range(101, 111));
	CHECK(x < y);
}


#ifdef __cpp_structured_bindings
using namespace Catch::Generators;
TEST_CASE("strlen", "[approvals]")
{
	auto [input, expected] = GENERATE(
		values<std::pair<std::string_view, size_t>>({
			{"one", 3u},
			{"two", 3u},
			{"three",5u} }));

	REQUIRE(input.size() == expected);

}

TEST_CASE("strlen2", "[approvals]")
{
	auto [input, expected] = GENERATE(
		table<std::string_view, size_t>({
			{"one", 3u},
			{"two", 3u},
			{"three",5u} }));

	REQUIRE(input.size() == expected);

}
struct Data { std::string str; size_t len; };

TEST_CASE("strlen3", "[approvals]")
{
	auto [input, expected] = GENERATE(
		values<Data>({
			{"one", 3u},
			{"two", 3u},
			{"three",5u} }));

	REQUIRE(input.size() == expected);

}



#endif 

TEST_CASE("More Generators")
{
	auto i = GENERATE(as<std::string>(), "a", "b", "c");
	SECTION("one")
	{
		auto j = GENERATE(range(8, 11), 2);
		CAPTURE(i, j);
		SUCCEED();
	}

}







// To define catch main:
//int main(int argc, char* argv[])
//{
//	Catch::Session s;
//	const auto exitCode = s.applyCommandLine(argc, argv);
//	if (exitCode != 0)
//	{
//		return exitCode;
//	}
//	return s.run(argc, argv);
//}
