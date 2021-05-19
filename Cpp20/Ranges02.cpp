#include <ranges>
#include <vector>
#include <format>
#include <iostream>

using namespace std;
using namespace ranges;


auto some_op(int v) -> int
{
	std::cout << "some_op\n";
	return v + 3;
}

int main_ranges02() {

	std::vector<int> v = { 1,2 };

	auto r = v | std::ranges::views::transform(some_op)
		| std::ranges::views::filter([](int i) { return i % 2 == 0; });

	for (int i : r)
	{
		std::cout << std::format("{} \n", i);
	}
	return 0;
}

int main_transformExample() {


	const auto vec = vector{ 1,2,3 };

	const auto modify = [](int x) { return x * 2; };

	const auto out2 = vec | std::ranges::views::transform(modify);

	return 0;
}