#include  <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;
using namespace std::chrono_literals;

void _date_time_example() {
	
	year_month_day today = floor<days>(std::chrono::system_clock::now());
	year_month_day first_day_this_month = today.year() / today.month() / 1;
	year_month_day last_day_this_month = today.year() / today.month() / last;
	
	year_month_day_last ymdl{ today.year(), month_day_last{month{2}} };
	year_month_day last_day_of_feb{ ymdl };
}

// Compute the number of days between two dates:
inline int number_of_days(sys_days const& first, sys_days const& last)
{
	return (last - first).count();
}
// Check whether a date is valid:
bool is_valid_example() {
	constexpr auto day = 2020y / January / 33;
	constexpr auto is_valid = day.ok();
	return is_valid;
}

// time of day
void time_of_day_example() {
	// time_of_day<std::chrono::seconds> td(13h + 12min + 11s);
	// std::cout << td << '\n'; // 13:12:11
}

// Create time points with date and time parts:
void time_point_example() {
	auto tp = sys_days{ 2020y / April / 1 }+ 12h + 30min + 30s;
	std::cout << tp;
}

//Determine the current time of day and express it with various precisions:
void time_of_day_with_precisions() {
	auto tp = std::chrono::system_clock::now();
	auto dp = floor<days>(tp);
	
	/*time_of_day<std::chrono::milliseconds> time{
		std::chrono::duration_cast<std::chrono::milliseconds>(tp - td)
	};*/
	
}

void woking_with_chrono_literals()
{
	auto total_seconds = 12345s;
	auto hours = duration_cast<std::chrono::hours>(total_seconds);
	auto minutes = duration_cast<std::chrono::minutes>(total_seconds % 1h);
	auto seconds = duration_cast<std::chrono::seconds>(total_seconds % 1min);
	std::cout << hours.count() << ':'
		<< minutes.count() << ':'
		<< seconds.count() << '\n'; // 3:25:45
}

void using_conversion_functions() {
	// Use the conversion functions  floor(), round(), and ceil() available in C++17 when rounding is necessary:
	auto total_seconds = 12345s;
	auto m1 = std::chrono::floor<std::chrono::minutes>(
		total_seconds); // 205 min
	auto m2 = std::chrono::round<std::chrono::minutes>(
		total_seconds); // 206 min
	auto m3 = std::chrono::ceil<std::chrono::minutes>(
		total_seconds); // 206 min
	auto sa = std::chrono::abs(total_seconds);
}

// compute gcd of abs(a) and abs(b)
constexpr intmax_t _Gcd_(intmax_t a, intmax_t b) {
	if (a == 0 && b == 0) {
		return 1;
	}
	a = _Abs(a);
	b = _Abs(b);

	while (0 != b)
	{
		const intmax_t a2 = a;
		a = b;
		b = a2 % b;
	}
	return a;
}



// standard ratio class 
template<intmax_t n, intmax_t d = 1>
struct ratio_ {
	static_assert(d != 0, "zero denominator");
	static_assert(-INTMAX_MAX <= n, "numerator too negative");
	static_assert(-INTMAX_MAX <= d, "denominator too negative");

	static constexpr intmax_t num = _Sign_of(n) * _Sign_of(d) * _Abs(n) / _Gcd(n, d);
	static constexpr intmax_t den = _Abs(d) / _Gcd(n, d);

	using type = ratio_<num, den>;
};

void Information_about_chrono_types()
{

	using nanoseconds = duration<long long, nano>;
	using microseconds = duration<long long, micro>;
	using milliseconds = duration<long long, milli>;
	using seconds = duration<long long>;
	using minutes = duration<int, ratio<60>>;
	using hours = duration<int, ratio<3600>>;
#if _HAS_CXX20
	using days = duration<int, ratio_multiply<ratio<24>, hours::period>>;
	using weeks = duration<int, ratio_multiply<ratio<7>, days::period>>;
	using years = duration<int, ratio_multiply<ratio<146097, 400>, days::period>>;
	using months = duration<int, ratio_divide<years::period, ratio<12>>>;
#endif // _HAS_CXX20

}


int time_zones()
{
	// Time zones include things like daylight saving time descriptions.

	// Access time zone database
	auto&& db = std::chrono::get_tzdb();

	auto* brussels{ locate_zone("Europe/Brussels") };

	auto* gmt{ locate_zone("GMT") };

	[[maybe_unused]] auto* current{ current_zone() };

	// Conversions between time zones:
	// Convert the current system time to GMT.
	[[maybe_unused]] auto gmt_time = gmt->to_local(system_clock::now());

	// Construct a UTC time.
	auto t{ sys_days{2020y / June / 22d} + 9h + 35min + 10s };
	// Convert UTC time to Brussels local time.
	[[maybe_unused]] auto brussels_time = brussels->to_local(t);

	/*zoned_time<hours> brusselsTime{
	brussels,local_days{2020y / June / 22d} };*/

	/*zoned_time<hours> newYorkTime{
	"America/New_York", brussels_time};*/

	// Construct UTC time from local time.



	return 0;
}



int year_month_day_example1() {
	// todays year month day.
	year_month_day today{ floor<days>(system_clock::now()) };


	system_clock::time_point t1{ sys_days{2020y / June / 22d} };

	year_month_day yearmonthday{ floor<days>(t1) };

	// full date with  timestamp:
	auto d2{ sys_days{2020y / June / 22d} + 9h + 35min + 10s };

	auto d3{ d2 + days{5} };

	// std::cout << d2 << '\n' << d3;

	auto d4{ d2 + years{1} };
	std::cout << d2 << std::endl;
	std::cout << d4 << std::endl; // we will have surprise.


	sys_days d2_days{ time_point_cast<days>(d2) };
	seconds d2_seconds{ d2 - d2_days };

	year_month_day ymd2{ d2_days };

	// add 1 year.

	year_month_day ymd3{ ymd2 + years{1} };
	auto d{ sys_days{ymd3} + d2_seconds };

	//std::cout << d2 << std::endl << d << std::endl;
	return 0;
}