import <iostream>;

int ptr[] = { 1, 2, 3 };

int main_easy_crash() // just a crash. 
{
	/* Without having Visual studio installed it's possible to fix crash in many ways.
	 0. Run tests with address sanitizer enabled.
	 1. Use WinDbg on target platform, here try to always keep symbols for release builds with special compiler flags.
	 2. create crash dump file and use it later to find issue.
			seems not 100% needed. $env:ASAN_SYMBOLIZER_PATH="C:\Program Files (x86)\Microsoft Visual Studio\2019\Preview\VC\Tools\MSVC\14.29.30036\bin\Hostx64\x64"
			'C:\Program Files\Microsoft Visual Studio\2022\Preview\VC\Tools\MSVC\14.31.30818\bin\Hostx64\x64\'
			$env:ASAN_SAVE_DUMPS="Project1.dmp"
			run program.exe
			place *.pdb file close to .exe so source info will be displayed in visual studio.
	*/

	int x{ 0 }, y{ 0 };
	for (int i = 0; i < 100; ++i)
	{
		std::cin >> x; std::cin >> y;
		ptr[x] = y;
		std::cout << ptr[x];
	}

	return ptr[x];
}