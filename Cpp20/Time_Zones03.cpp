#include <map>
#include <thread>
#include <iostream>
#include <chrono>
#include <algorithm>
#include <ranges>

using namespace std::literals;
using namespace std::ranges;
namespace {
	void ex0() {
		auto firstDay = 2021y / 1 / 31;
		auto lastDay = 12 / 31d / 2021;

		for (auto d = firstDay; d <= lastDay; d += std::chrono::months{ 1 })
		{
			if (d.ok()) {
				std::cout << d << ": Party \n";
			}
			else {
				std::cout << d.year() / d.month() / 1 + std::chrono::months{ 1 }
				<< ": Party \n";
			}
		}
	}


	void ex1() {
		auto firstDay = 2021y / 1 / std::chrono::last;
		auto lastDay = 12 / 31d / 2021;

		for (auto d = firstDay; d <= lastDay; d += std::chrono::months(1))
		{
			std::cout << std::format("{:13%B %d}: party\n", d);
		}
	}
	void ex2() {
		auto firstDay = 2021y / 1 / std::chrono::last;
		auto lastDay = 12 / 31d / 2021;

		for (auto d = firstDay; d <= lastDay; d += std::chrono::months(1))
		{
			auto tp{ std::chrono::local_days{d} + 18h + 30min };
			std::chrono::zoned_time timeLocal{ std::chrono::current_zone(),tp };

			std::cout << std::format("{0:13%B %d}: Party {0:%X %Z}\n", timeLocal);

			std::chrono::zoned_time timeLA{ "America/Los_Angeles", timeLocal };
			std::cout << std::format("{:>19}: {:%X %Z}\n", "LA", timeLA);
		}

	}

	void print(const std::ranges::input_range auto& coll) {
		for (const auto& e : coll) {
			std::cout << e << ' ';
		}
		std::cout << '\n';
	}

	void ex3() {
		std::map<std::chrono::sys_days, int> locs;
		auto firstDay = 2021y / 1 / std::chrono::last;
		auto lastDay = 12 / 31d / 2021;
		for (auto d = firstDay; d <= lastDay; d += std::chrono::months{ 1 })
		{
			locs.emplace(d, 0);
		}

		{
			std::vector<std::jthread> tasks;
			for (int i = 0; i < 5; ++i) {
				tasks.push_back(
					std::jthread{
						[&locs](std::stop_token st)
					{
					while (!st.stop_requested()) {
						for (auto& [k, c] : locs) {
							std::atomic_ref<int> ac(c);
							ac++;
						}
					}
					} });
			}

			for (auto& t : tasks) {
				t.request_stop();
			}
		}
		auto newview = locs | std::views::values;
		print( newview);
	}

}
//
//int main() {
//	ex2();
//	return 0;
//}