#include <filesystem>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <iostream>

namespace
{
	class Data
	{
		int d;
	};

	std::mutex key;
	std::condition_variable_any cv;
	std::queue<Data> q;

	class op_was_canceled
	{
	};

	Data wait_for_data(std::stop_token st)
	{
		std::unique_lock lock(key);

		if (!cv.wait(lock, st, []
		{
			return !q.empty();
		}))
		{
			throw op_was_canceled();
		}
		Data res = q.front();
		q.pop();
		return res;
	}
}

namespace
{
	Data read_data(int handle)
	{
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(10s);
		return Data{};
	}

	Data read_file(std::stop_token st, std::filesystem::path filename)
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
		return Data{};
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
