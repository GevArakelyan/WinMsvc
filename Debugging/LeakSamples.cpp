#include <chrono>
#include <thread>
#include <iostream>

using namespace std::chrono;
/*
	Sysinternals Video Library - Troubleshooting Memory Problems  https://www.youtube.com/watch?v=QmF0DymemGs
	Examples of leak: user process monitor tool to find the bug.
	Testlimit.exe -m 1 -e 1
	Testlimit.exe -h  | will leak the handle and increase kernel paged heap size.
*/
int main_Leak() {

	for (size_t i = 0;; i++)
	{
		new char[1024];
		std::this_thread::sleep_for(.5s);
	}
	return 0;
}
/*
	Mysteries of Memory Management Revealed,with Mark Russinovich (Part 1 of 2)WCL405 HD
	https://www.youtube.com/watch?v=TrFEgHr72Yg

	Mysteries of Memory Management Revealed (Part 2/2)
	https://www.youtube.com/watch?v=6KZdNsq1YV4
*/
