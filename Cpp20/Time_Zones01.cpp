// Converting time between time zones.
// time_of_day type.
/*
System clock measures Unix time and therefore uses UTC as the
default time zone. However, we are usually interested in the
local time and, sometimes, in the time in some other time zone.


*/

#include <chrono>
#include <iostream>
//#include <date.h>


using namespace std;
using namespace std::chrono;

void examples()
{
	// to retrieve the local time zone from the time zone database.
	
	auto current_zone_obj = std::chrono::current_zone();
	
	// locate_zone to retrieve a particular time zone from database.
	
	// zoned_time class used to represent a time point in a 
	// particular time zone.

	// to retrieve and display the current local time.
	auto time = zoned_time{ current_zone(), system_clock::now() };
	//std::cout << time << '\n';
	
	//to display the current time in another time zone.
	auto time1 = zoned_time{ locate_zone("Europe/Rome"), system_clock::now() };
	
	// To display the current local time with proper locale formatting.
	// In this example, the current time is Romanian time, and the locale being
	// used is for Romania:
	auto time3 = zoned_time{ current_zone(), system_clock::now() };
	//std::cout << date::format(std::locale{ "ro_RO" }, "%c", time);
	
	auto time4 = local_days{ 2020y / June / 1 } + 12h + 30min + 45s + 256ms;
	auto ny_time = zoned_time<milliseconds>{ locate_zone("America/New_York"), time4 };
	// std::cout << ny_time;
	
	// Convert a time point in a particular time zone into a time point
	// in another time zone. In the following example, we convert the time
	// from New York into the time in Los Angeles:
	auto la_time = zoned_time<milliseconds>{ locate_zone("America/Los_Angeles"), ny_time };
	// std::cout << la_time;
}

/*  The standard defines several clocks :
1. system_clock: This uses the real-time clock of the current system to represent time points.
2. high_resolution_clock: This represents a clock that uses the shortest possible
	tick-period on the current system.
3. steady_clock: This indicates a clock that is never adjusted. This means that, unlike the other clocks,
as the time advances, the difference between two time points is always positive.
4. utc_clock: This is a C++20 clock for Coordinated Universal Time.
5. tai_clock: This is a C++20 clock for International Atomic Time.
6. gps_clock: This is a C++20 clock for Global Positioning System time.
7. file_clock: This is a C++20 clock used for expressing file times.
*/

template <typename T>
void print_clock() {
	std::cout << "Precision: " << (1000000.0 * double(T::period::num)) / (T::period::den)
		<< '\n';
	std::cout << "steady: " << T::is_steady << '\n';
}

void more_info() {
	// The following example prints the precision of the first three clocks in this list
	// (the ones available in C++11), regardless of whether it is steady(or monotone) or not:
	print_clock<system_clock>();
	// p: 0.1 steady:0 ==> means that system_clock has resolution of 0.1 milliseconds and 
	// is not monotone clock.
	print_clock<high_resolution_clock>();// P: 0.001 steady: 1
	print_clock<steady_clock>();// p: 0.001 steady: 1
	// above both have resolution of 1 nanosecond and are monotone clocks.

	// The steadiness of a clock is important when measuring the execution time
	// of a function, because if the clock is adjusted while the funciton runs, 
	// the result will not yield the actual execution time, and values can even
	// be negative.
}
