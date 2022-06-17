#include <ranges>
#include <vector>
#include <format>
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <set>
#include <map>
#include <array>

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

void print(const std::ranges::input_range auto& coll) {
	for (const auto& e : coll) {
		std::cout << e << ' ';
	}
	std::cout << '\n';
}

void ex() {
	std::vector<int> v{ 1,2,3 ,4,-1,4,5 };
	print(v | std::views::take(3));
	print(v | std::views::drop(3));

	//print(v | std::views::drop_while([](int e) { return e < 0; }));
	/*print(v | std::views::take(3)
		| std::views::transform([](auto v) {
			return std::to_string(v) + 's';
			}
	));*/
}

template <auto Val>
struct EndValue {
	bool operator == (auto pos) const
	{
		return *pos == Val;
	}
};

void example01() {

	std::vector<int> v{ 1,2,3 ,4,-1,4,5 };

	print(v);

	std::ranges::subrange rg(v.begin() + 1, EndValue<-1>());

	print(rg);
	print(rg | std::views::take(3) | std::views::transform([](auto v) {
		return std::to_string(v) + 's';
		}));
}
// Literal types with public members can be used in non type template
// parameters.
struct Coord {
	double x = 0, y = 0, z = 0;

	/* Old
	friend std::ostream& operator << (std::ostream& os, const Coord& c) {
		return os << "(" << c.x << ", " << c.y << ", " << c.z << ")";
	}*/

	// New
	friend std::ostream& operator << (std::ostream& os, const Coord& c) {
		return os << std::format("[{}/{}/{}]", c.x, c.y, c.z);
	}
	// New
	auto operator <=> (const Coord& c) const = default;

	/* Old
	friend bool operator == (const Coord& lhs, const Coord& rhs) {
		return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
	}*/
};

void ex3() {

	std::vector points{ Coord{3,2,1}, Coord{1,2,3}, Coord{0,0,0} };

	std::ranges::subrange rg{ points.begin(), EndValue < Coord{} > {} };

	print(rg);
	//std::sort(rg); // Error:
	std::ranges::sort(rg);
}
// Const views might not support iterating
// - Because they might have to modify their state while iterating
void ex4() {
	std::vector vec{ 1,2,3,4,5 };
	print(vec | std::views::drop(3));

	// Error:
	//print(vec | std::views::filter([](int i){  return i % 2 == 0; }));


	std::list lst{ 1,2,3,4,5 };
	//print(lst | std::views::drop(3)); // Error:

	/*
		No iteration with const:

		Always: filter, drop_while, split

		Sometimes: drop, reverse, join
	*/
}
// Solution to above problem: write universal or forwarding references.
void Betterprint(std::ranges::input_range auto&& coll) {
	for (const auto& e : coll) {
		std::cout << e << ' ';
	}
	std::cout << '\n';
}

void ex5() {
	std::vector vec{ 1,2,3,4,5 };
	Betterprint(vec | std::views::drop(3));

	Betterprint(vec | std::views::filter([](int i) {  return i % 2 == 0; }));


	std::list lst{ 1,2,3,4,5 };
	Betterprint(lst | std::views::drop(3)); // Error:
}

void Print2(std::ranges::view auto call) {
	for (const auto& e : call) {
		std::cout << e << ' ';
	}
	std::cout << '\n';
}
void ex6() {
	std::vector vec{ 1,2,3,4,5 };
	std::set s{ 1,2,3,4,5 };
	//Print2(vec);
	//Print2(s);
	Print2(std::views::all(vec));
	Print2(s | std::views::all);

	Print2(vec | std::views::drop(3));
	Print2(s | std::views::drop(3));
}

// Pipelines of Range adaptors

void ex7() {
	std::map<std::string, int> composer{
		{ "Bach", 1685},
		{ "Mozart", 1756},
		{"Bethoven", 1770},
		{"Tchaikovsky", 1840},
		{"Chopin", 1810},
		{"Vivaldi", 1678}
	};

	namespace vs = std::views;
	for (const auto& elem : composer
		| vs::filter([](auto& y) { return y.second >= 1700; })
		| vs::take(3)
		| vs::elements<0>) // names only
	{
		std::cout << elem << '\n';
	}
	// std::views::elements does not work for user defined types
}

// Merge a list of sizes at compile time
template<std::ranges::input_range C, std::integral... Args>
consteval auto mergeSizes(C rg, Args... vals) {
	std::vector<std::ranges::range_value_t<C>> v{ std::ranges::begin(rg),
	std::ranges::end(rg) };

	(..., v.push_back(vals));

	std::ranges::sort(v);

	constexpr auto size = std::ranges::size(rg) + sizeof...(vals);
	std::array<std::ranges::range_value_t<C>, size> ret{};
	std::ranges::copy(v, ret.begin());
	return ret;
}

void ex8() {
	constexpr std::array a{ sizeof(int), sizeof(std::string),
	sizeof(std::set<int>) };

	auto allSizes = mergeSizes(a, sizeof(long), sizeof(Coord));
	for (const auto& i : allSizes) {
		std::cout << i << " ";
	}
}
// Now let's have allSizes without duplication:
template<std::ranges::input_range C, std::integral... Args>
consteval auto mergeSizesUnique(C rg, Args... vals) {
	std::vector<std::ranges::range_value_t<C>> v{ std::ranges::begin(rg),
	std::ranges::end(rg) };

	(..., v.push_back(vals));

	std::ranges::sort(v);

	constexpr auto maxSize = std::ranges::size(rg) + sizeof...(vals);
	std::array<std::ranges::range_value_t<C>, maxSize> ret{};
	auto res = std::ranges::unique_copy(v, ret.begin());
	return std::pair{ ret, res.out - ret.begin() };
}

void ex9() {
	constexpr std::array a{ sizeof(int), sizeof(std::string),
	sizeof(std::set<int>) };

	auto [arr, size] = mergeSizesUnique(a, sizeof(long), sizeof(Coord));
	auto allSizes = std::views::counted(arr.begin(), size);

	for (auto& i : allSizes) {
		std::cout << i << ' ';
	}
}