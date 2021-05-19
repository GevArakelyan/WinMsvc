#include <concepts>

// on gcc you can use only after gcc 10.3

namespace lib
{
	template<typename T>
	concept Addable = std::regular<T>
		&& requires (T & o, T const& a, T const& b) {
			{a + b} -> std::convertible_to<T>;
			{ o += b} -> std::same_as<T&>;
	};

	template<typename T>
	T sum(T const& a, T const& b) {
		return a + b;
	}
}

int main_concepts02() {

	auto r = lib::sum(1,2);

	lib::Addable auto r1 = lib::sum(1.2, 3.4);
	return 0;
}

