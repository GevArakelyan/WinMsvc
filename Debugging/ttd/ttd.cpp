import <iostream>;
import <string>;
import <mutex>;
import <fstream>;
import <vector>;

namespace
{

	/*
		Here we can't find issue by just creating dump file, or even with the address sanitizer there will be no much help.
		//Here TTD comes to help: https://channel9.msdn.com/Shows/Defrag-Tools/Defrag-Tools-186-Time-Travel-Debugging-Advanced
	*/
	int* freeObjectList = new int[100];

	auto init_ptr(int x)
	{
		const auto result = freeObjectList;
		if (x == 0)
		{
			freeObjectList = nullptr;
		}
		return result;
	}


	int ex1()
	{
		int x{ 0 };
		for (int i = 0; i < 100; ++i)
		{
			std::cin >> x;

			int* ptr = init_ptr(x);
			ptr[x] = 1;

			std::cout << ptr[x];
		}
		return 0;
	}
}




