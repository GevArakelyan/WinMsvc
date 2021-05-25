#include <iostream>
#include <experimental\generator>

using namespace std::experimental;

namespace ex_generator
{
    generator<int> gen()
    {
        for (int i = 0; ; ++i)
        {
            co_yield i;
        }
    }


    int main(int argc, char* argv[])
    {
        for (int x : gen())
        {
            std::cout << x;
        }
        return 0;
    }
}
//----------------------------------------------
#include <future>
#include <coroutine>
#include <iostream>

using namespace  std;

struct resumable_thing
{
    struct promise_type
    {
        resumable_thing get_return_object()
        {
            return resumable_thing(coroutine_handle<promise_type>::from_promise(*this));
        }
        auto initial_suspend()
        {
            return suspend_never{};
        }
        auto final_suspend() noexcept
        {
            return suspend_never{};
        }

        void return_void()
        {
        }

        void unhandled_exception()
        {
        }
    };

    coroutine_handle<promise_type> _coroutine = nullptr;

    resumable_thing() = default;
    resumable_thing(resumable_thing&& other)
        : _coroutine(other._coroutine)
    {
        other._coroutine = nullptr;
    }
    resumable_thing& operator=(resumable_thing&& other)
    {
        if (&other != this)
        {
            _coroutine = other._coroutine;
            other._coroutine = nullptr;
        }
    }

    explicit resumable_thing(coroutine_handle<promise_type> coro)
        : _coroutine(coro)
    {
    }
    ~resumable_thing()
    {
        if (_coroutine)
        {
            _coroutine.destroy();
        }
    }
};

resumable_thing fun()
{
    std::cout << "prepare long running stage\n";
    co_await suspend_always{};
    for (int i = 0; ; ++i)
    {
        co_await suspend_always{};
        std::cout << "counter: resumed\n";
    }
}

int main_co_await(int argc, char* argv[])
{
    auto res = fun();

    res._coroutine.resume();
    res._coroutine.resume();
    res._coroutine.resume();
    return 0;
}


