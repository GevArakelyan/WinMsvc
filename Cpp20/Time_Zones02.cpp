#include <chrono>
#include <iostream>
#include <string>

using namespace std::chrono;

//void printStartEndTimes(const local_days& local_days,
//	const duration<int, std::ratio<3600, 1>>& duration,
//	const hours& hours, const std::initializer_list<const char*>& initializers);

template<typename ZonedTime>
auto getMinutes(const ZonedTime& zonedTime) {
	return floor<minutes>(zonedTime.get_local_time());
}

void printStartEndTimes(const local_days& localDays,
	const hours& h,
	const hours& duration,
	const std::initializer_list<std::string>& timeZones)
{
	zoned_time startDate{ current_zone(),localDays + h };
	zoned_time endDate{ current_zone(),
		localDays + h + duration };
	std::cout << "Local time: [" << getMinutes(startDate) << ", "
		<< getMinutes(endDate) << "]\n";

	auto longestStringSize = std::max(timeZones,
		[](const std::string& a,const std::string& b)
		{return a.size() < b.size(); }).size();
	for (auto timeZone : timeZones)
	{
		std::cout << " " << std::setw(longestStringSize + 1) << std::left
			<< timeZone
			<< "[" << getMinutes(zoned_time(timeZone, startDate))
			<< ", " << getMinutes(zoned_time(timeZone, endDate))
			<< "]" << "\n";
	}
}


int main_timezones02(int argc, char* argv[])
{
	using namespace std::string_literals;

	auto classDay{ std::chrono::year(2022) / 6 / 1 };
	auto duration = 1h;
	auto timeZones = {
		"America/Los_Angeles"s,"America/Denver"s,
		"America/New_York"s,"America/Chicago"s,
		"Asia/Singapore"s,"Asia/Tokyo"s,
		"Europe/London"s,"Europe/Paris"s,
		"Europe/Minsk"s,"Europe/Moscow"s,
	};

	for (auto startTime : { 7h,13h,17h })
	{
		printStartEndTimes(std::chrono::local_days{ classDay },
			startTime, duration, timeZones);
		std::cout << "\n";
	}

	return 0;
}
