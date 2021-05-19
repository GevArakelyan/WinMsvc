#include <type_traits>
import <iostream>;




template <typename T, typename... Ts, typename U>
int f(T t, U u, const Ts&...ts)
{
	std::cout << t << " " << u << std::endl;
	(std::cout << ... << ts);
	return 0;
}

int Gready_matching() {
	// .
	// 1. A parameter after a template parameter pack can never be explicitly specified.
	// So it is always deduced.
	f(1, 2); // ts = <>
	f<int, int>(1, 2, 3); // ts=<int>
	f<int, double, const char[2]>(1, 2, 3, "4"); // ts = <int,double>

	return 0;
}
template <typename... Ts, typename T>
int fun(Ts... values, T value) {
	(std::cout << ... << values);
	std::cout << std::endl;
	std::cout << value << std::endl;
	return 0;
}

int Fair_matchine() {
	// Ts is always explicit
	fun(1); // Ts=<>
	fun<>(1); // Ts=<>
	fun<int, double>(1, 3.4, 3); // Ts=<int,double>
	//fun<int, int>(1, 2); // Error
	return 0;
}


template <typename... Ts, typename... Us>
int fun2(Ts... ts, Us... us)
{
	(std::cout << ... << ts);
	std::cout << std::endl;
	(std::cout << ... << us);
	return 0;
}

int Quiz() {

	// 1. Us is always deduced (greedy matching)
	// 2. Ts is always explicit (fair matching)
	fun2(1);	// Ts=<>
	fun2(1,"2"); // Ts=<>
	fun2<int,char>(1,'2'); // Ts=<int,char>
	fun2<int,char>(1,'2',"three"); // Ts=<int,char>
	
	return 0;
}