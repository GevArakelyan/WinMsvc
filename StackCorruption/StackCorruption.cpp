#include <array>
#include <stdio.h>
#include <string.h>

void GetCppConGreeting(wchar_t* buffer, size_t size)
{
    wchar_t const* const message = L"HELLO FROM THE WINDBG TEAM. GOOD LUCK IN ALL OF YOUR TIME TRAVEL DEBUGGING!";

    //wcscpy_s(buffer, size, message);
    for (auto i = 0; i < size; ++i)
    {
        buffer[i] = message[i];
    }
}

int main()
{
    std::array <wchar_t, 76> greeting{};
    GetCppConGreeting(greeting.data(), sizeof(greeting));

    wprintf(L"%ls\n", greeting.data());
    wprintf(L"%ls\n", greeting.data());
    wprintf(L"%ss\n", greeting.data());

    return 0;
}