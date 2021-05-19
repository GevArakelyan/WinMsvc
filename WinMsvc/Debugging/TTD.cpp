#include <iostream>
#include <string>
#include <mutex>
#include <fstream>
#include <vector>

int ptr[] = {1, 2, 3};

int main_easy_crash() // just a crash. 
{
	/* Without having Visual studio installed it's possible to fix crash in many ways.
	 0. Run tests with address sanitizer enabled.
	 1. Use WinDbg on target platform, here try to always keep symbols for release builds with special compiler flags.
	 2. create crash dump file and use it later to find issue.
			seems not 100% needed. $env:ASAN_SYMBOLIZER_PATH="C:\Program Files (x86)\Microsoft Visual Studio\2019\Preview\VC\Tools\MSVC\14.29.30036\bin\Hostx64\x64"
			$env:ASAN_SAVE_DUMPS="Project1.dmp"
			run program.exe
			place *.pdb file close to .exe so source info will be displayed in visual studio.
	*/

	int x{0}, y{0};
	for (int i = 0; i < 100; ++i)
	{
		std::cin >> x; std::cin >> y;
		ptr[x] = y;
		std::cout << ptr[x];
	}
	
	return ptr[x];
}

/*
	Here we can't find issue by just creting dump file, or even with the address sanitizer there will be no much help.
	//Here TTD comes to help: https://channel9.msdn.com/Shows/Defrag-Tools/Defrag-Tools-186-Time-Travel-Debugging-Advanced
*/
int* freeObjectList = new int[100];

auto InitPtr(int x)
{
	auto ptr = freeObjectList;
	if (x == 0)
	{
		freeObjectList = 0;
	}
	return ptr;
}


//int main_harder_crash()
int main()
{

	int x{0};
	int* ptr = nullptr;
	for (int i = 0; i < 100; ++i)
	{
		std::cin >> x;
		ptr = InitPtr(x);
		ptr[x] = 1;
		std::cout << ptr[x];
	}
	return 0;
}














//
//In summary, reachability of declarations implicitly and transitively propagates to all consumers of a
//module�however indirect�but visibility of declared names does not.Luckily, though, reachable definitions
//typically suffice for you to use a module�s interface without having to import any extra modules, especially if
//you embrace the use of auto.
