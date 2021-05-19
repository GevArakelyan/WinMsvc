//#include <iostream>
//
//
////https://www.youtube.com/watch?v=g2iyNH2Gh1k | 15:32 | C++ Siberia 2019: Антон Полухин, C++ на практике
//// boost::interprocess::mapped_region
////#define BOOST_INTERPROCESS_BOOTSTAMP_IS_SESSION_MANAGER_BASED
//
//#include <boost/interprocess/managed_mapped_file.hpp>
//#include <boost/interprocess/managed_shared_memory.hpp>
//#include <Windows.h>
//#include <chrono>
//#include <thread>
//
//
//using namespace std::chrono;
//using namespace boost::interprocess;
//
//bool fixBoostIpcSharedMem6005issue()
//{
//	bool result = false;
//
//	HANDLE hEventLog = ::RegisterEventSourceA(NULL, "EventLog");
//	if (hEventLog)
//	{
//		const char* msg = "simple boost shared memory fix for 6005";
//
//		if (::ReportEventA(hEventLog, EVENTLOG_INFORMATION_TYPE, 0, 6005, NULL, 1, 0, &msg, NULL))
//			result = true;
//
//		::DeregisterEventSource(hEventLog);
//	}
//
//	return result;
//}
//namespace FastReader01
//{
//	int main() {
//
//		//fixBoostIpcSharedMem6005issue();
//		try
//		{
//			std::this_thread::sleep_for(10s);
//			//managed_shared_memory file(open_or_create, "MySharedMemory", 65565);
//			static_assert(4096 * 16 == 65536, "error");
//
//
//			managed_mapped_file file(open_or_create, "MySharedMemory.txt", 4096 * 16);
//
//
//			auto StartSize = file.get_free_memory();
//
//			auto sptr = file.allocate(1);
//
//			auto EndSize = file.get_free_memory();
//
//			std::cout << "Start Size == " << StartSize << std::endl;
//			std::cout << "Allocated Size == " << 1 << std::endl;
//			std::cout << "End Size == " << EndSize << std::endl;
//
//
//
//			file.flush();
//			//managed_mapped_file file(open_only, "MySharedMemory");
//		}
//		catch (const boost::interprocess::interprocess_exception& e)
//		{
//			std::cout << "exception" << e.what();
//		}
//
//		//file << "hello";
//
//		//shared_memory_object::remove("MySharedMemory"); 
//		return 0;
//	}
//}