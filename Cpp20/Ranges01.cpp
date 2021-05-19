#include <ranges>
#include <unordered_map>
#include <string_view>
#include <iostream>
#include <algorithm>

using namespace std::ranges;
using namespace std;

namespace Ranges01 {
	void example1()
	{
		const char* ptr = "UserName@gmail.com";

		auto it = std::ranges::find(ptr, std::unreachable_sentinel, '.');


		//auto it = std::ranges::find(ptr, value_sentinel{'\0'}, '.');

	}

	void example2() {
		std::unordered_map<int, std::string> map;


		auto it = std::ranges::find(map.cbegin(), map.cend(), "hello"sv,
			[](const auto& v) -> string_view { return v.second; });


		auto it2 = std::ranges::find(map, "hello"sv,
			[](const auto& v) -> string_view { return v.second; });
	}

	void example3() {

		std::string str = "abc";

		for (auto c : std::views::reverse(str)) {
			std::cout << c;
		}
		// or 
		std::ranges::copy(std::views::reverse(str),
			std::ostream_iterator<char>(std::cout));

	}

	void example4() {

		std::string_view str = "Ranges! Ara! Awesome!";

		for (auto word : std::views::split(str, ' ')) {
			// print word.
		}
		// or 
		for (auto word : str | std::views::split(' '))
		{
			std::ranges::copy(word, std::ostream_iterator<char>(std::cout));
			std::cout << '\n';
		}
		// harder case
		constexpr auto f = [](char c) { return c != '!'; };

		for (auto word : str | std::views::filter(f) | std::views::split(' '))
		{
			// ...
		}
		namespace v = std::views;

		constexpr auto t = [](char c) { return std::tolower(c); };

		for (auto word : str | v::filter(f) | v::transform(t) | v::split(' '))
		{
			// ....
		}

	}

	int main() {

		return 0;
	}
}