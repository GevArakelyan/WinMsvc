#include <filesystem>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <iostream>
#include <format>

using namespace std;
namespace
{

	struct Employee
	{
		int Id;
	};
	std::ostream& operator<<(std::ostream& ostream, const Employee& employee)
	{
		ostream << std::format("Employee had id=={}", employee.Id);
		return ostream;
	}

	std::mutex key;
	std::condition_variable_any cv;
	std::queue<Employee> q;

	class op_was_canceled
	{
	};

	Employee wait_for_new_employee(std::stop_token st)
	{
		std::unique_lock lock(key);

		if (!cv.wait(lock, st, [] { return !q.empty(); }))
		{
			throw op_was_canceled();
		}

		Employee res = q.front();
		q.pop();
		return res;
	}

	void present_new_employees(std::stop_token st)
	{
		while (true)
		{
			std::this_thread::sleep_for(3s);
			auto Emp = wait_for_new_employee(st);
			std::cout << Emp;
		}
	}
}

int main_stop_token()
{

	std::jthread Worker(present_new_employees);


	int Id{};
	while (true)
	{
		std::cin >> Id;
		if (Id < 0)
		{
			Worker.request_stop();
			Worker.join();
			break;
		}
		if (Id > 0)
		{
			std::unique_lock lock(key);
			std::this_thread::sleep_for(3s);
			q.emplace(Id);
		}
		else if (Id == 0)
		{
			cv.notify_all();
		}
	}
	return 0;
}

namespace
{
	Employee read_data(int handle)
	{
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(10s);
		return Employee{};
	}

	Employee read_file(std::stop_token st, std::filesystem::path filename)
	{
		auto handle = 1;//open_file(filename);

		auto threadid = std::this_thread::get_id();
		std::cout << "called from  thread" << threadid;

		std::stop_callback cb(st, [&]
		{
			auto threadid = std::this_thread::get_id();
			std::cout << "called from  thread" << threadid;
			//usefull examples ( notify others, close file_handle...)
		});
		read_data(handle);

		threadid = std::this_thread::get_id();
		std::cout << "called from  thread" << threadid;
		return Employee{};
	}
}

namespace
{
	void thread_func(std::stop_token st,
					 std::string arg1, std::string arg2)
	{
		while (!st.stop_possible())
		{
			//do_some_staff ...
		}
	}

	void using_thread_func(std::string s)
	{
		std::jthread t(thread_func, s, s);
		//do_othe_stuff ...
	}
}
