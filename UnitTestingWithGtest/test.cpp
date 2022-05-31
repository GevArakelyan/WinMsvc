#include "pch.h"





int main(int argc, char** argv)
{
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}




TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
// gg.exe --gtest_list_tests

class Fixture : public ::testing::TestWithParam<int>
{
	public:
	Fixture()
	{
		std::cout << "Fixture Constructor" << std::endl;
	}
	~Fixture()
	{
		std::cout << "Fixture Destructor" << std::endl;
	}

};

TEST_P(Fixture, SomeTest) {
	EXPECT_TRUE(1 == 1);
}

INSTANTIATE_TEST_SUITE_P(
	InstantiationName,
	Fixture,
	::testing::Values(1, 2)
);


struct Data {
	std::string input;
	std::string expected;
};
std::ostream& operator<<(std::ostream& os, const Data& d) {
	return os << "input: " << d.input << " expected result" << d.expected;
}

struct  StringEncoder {
	static std::string Encode(std::string input) {
		return input;
	}
};

class StringEncoderTests : public ::testing::TestWithParam<Data> {};

TEST_P(StringEncoderTests, EncoderExample) {
	auto& row = GetParam();

	auto result = StringEncoder::Encode(row.input);

	ASSERT_EQ(row.expected, result);

}

INSTANTIATE_TEST_SUITE_P(EncodingTestsInstantiation,
	StringEncoderTests,
	::testing::Values(
		Data{"abc", "abc"},
		Data{"123", "123"},
		Data{"", ""}
	));

/*
	Range(begin,end, [step]);
	Values(v1,v2,...);
	ValuesIn(Container);
	ValuesIn(begin,end);
	Bool();
	Combine(g1,g2...);
*/


