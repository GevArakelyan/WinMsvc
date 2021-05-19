#include <optional>
#include <variant>
#include <string>
#include <iostream>
#include <cassert>

using namespace std;

int main_algebraic_types()
{
	std::string s = string("abc", 2);

	optional<string> o(std::in_place, "abc", 3);

	auto o_value = o.value_or("def");


	// we can compare optinals and std::nullopt compares less than any value of T.

	// pair and tuple are ordered sequences, they're compared lexicographically
	// variant<ts...> can be thought as an ordered sequence { index(), value}, compared lexicographically




	variant<int, string> v1(
		in_place_type<string>, "abc", 2
	);
	variant<int, string> v2(in_place_index<1>, "abc", 2);


	auto Printme = [](const auto& value) {
		cout << value << endl;
	};

	std::visit(Printme, v1);

	std::visit(Printme, v2);

	try
	{
		v1.emplace<string>("throw exception");
	}
	catch (const std::exception&)
	{
		assert(v1.valueless_by_exception());
		assert(v1.index() == size_t(-1));
		// this may only happen with emplace function.
		// = operator will copy and then swap so it more safe.
	}


	{
		tuple t = make_tuple(1, 2, 3);
		auto pr = make_pair(23, false);

		// you can have tuple of reference types.
		int a = 1, b = 2, c = 3, d = 4;
		tuple<int&, int&> ab{ a,b };
		tuple<int&, int&> cd{ c,d };

		ab = cd;
		assert(a == 3 && b == 4);

		auto ab1 = make_tuple(std::ref(a), std::ref(b));

		auto ab2 = std::tie(a, b);

		auto ab3 = std::forward_as_tuple(a, b);

		static_assert(std::is_same_v<decltype(ab1), std::tuple<int&, int&>>);


		// how to constract pair by invoking two ctors.
		string s;
		pair<string, string> pair2ctor(
			piecewise_construct,
			forward_as_tuple("a", 1),
			forward_as_tuple(move(s))
		);

		/*
			tuple<int,int,int> fun();


			int x , y;

			std::tie(x,y, std::ignore) = fun();


		*/

	}
	return 0;
}