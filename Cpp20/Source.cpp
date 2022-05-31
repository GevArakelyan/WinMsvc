#include "cppcoro01.h"
#include <vector>
#include <thread>
#include <chrono>
#include "Source.h"
#include <iostream>

using namespace std::chrono_literals;

int main1() {
	
	auto x1 = NewFunction(1);
	auto x2 = NewFunction(2);

	std::cout << x1 << " " << x2;
	
	return 0;
}

int NewFunction(int time)
{
	for (int i =0; i < time;++i ) {
		std::this_thread::sleep_for(1s);

		int* ptr = new int(42);
	}
	return time * 2;
}
