#include <iostream>
#include <fstream>
#include <mutex>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono_literals;
/* 7th edition part 1, 37 page Windows Internals book.

			Finding who has opened sysinternals.txt file.
			Resouce manager | process explorer
						Search Handles 
Each service-hosting process is identified by the service group it is hosting.
As with Process Explorer, selecting a process (by clicking its associated check box) will display a list of
named handles opened by the process, as well as a list of modules (such as DLLs) that are loaded in the
process address space. The Search Handles box can also be used to search for which processes have
opened a handle to a given named resource 
*/
int main_Search_Handles() 
{

	{ // need to wait and keep file open to be able to search it.
		std::ofstream file("sysinternals.txt");

		std::string s = "Hello panda";

		file << s;

	}

	std::this_thread::sleep_for(35s);



	return 0;
}

/*
page 102. 
	ShellExecute and ShellExecuteEx. These functions can accept any file (not just executables) and try
	to locate the executable to run based on the file extensions and the registry settings at HKEY_CLASSES_
	ROOT.

page 215
	For example, if process A has 10 runnable threads, process B has 2 runnable threads,
	and all 12 threads are at the same priority, each thread would theoretically receive
	one-twelfth of the CPU time. That is, Windows wouldn’t give 50 percent of the CPU
	to process A and 50 percent to process B.

page 219 How to change process/thread priority.
	cmd /c start /low Notepad.exe. | You'll need to be admin to run /Realtime.

page 232
	The length of the clock interval varies according to the hardware platform. The frequency of the clock
interrupts is up to the HAL, not the kernel. For example, the clock interval for most x86 uniprocessors is
about 10 milliseconds (note that these machines are no longer supported by Windows and are used here
only for example purposes),
and for most x86 and x64 multiprocessors it is about 15 milliseconds.
This clock interval is stored in the kernel variable KeMaximumIncrement as hundreds of nanoseconds.


*/


namespace Memory_Management
{
/*
	The subset of a process’s virtual address space that is physically resident is called the working set.
	
page 311
	Mapped file pages can also be written back to their original files on disk
with an explicit call to FlushViewOfFile
or by the mapped page writer as memory demands dictate.

One extremely common use for reserving a large space and committing portions of it as needed
is the user-mode stack for each thread. When a thread is created, a stack is created by reserving a
contiguous portion of the process address space. (The default size is 1 MB but you can override this size
with the CreateThread and CreateRemoteThread(Ex) function calls or change it on an executable
image basis by using the /STACK linker flag.)



*/


}