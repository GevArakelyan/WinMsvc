
## To install using vcpkg or cmake.
 
```
find_package(Catch2 CONFIG REQUIRED)
target_link_libraries(main PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)
```

### listener example:
```
class testRunListener : public Catch::EventListenerBase
{
public:
using Catch::EventListenerBase::EventListenerBase;

void testRunStarting(Catch::TestRunInfo const&) override
{
    lib_foo_init();
}

void startRun(Catch::TestGroupNode const& groupNode) override
{
    ...
}
};

CATCH_REGISTER_LISTENER(testRunListener)
---------------------
You can also use benchmarking.
BENCHMARK("FACTORIAL 30")
{
    return factorial(30);
}; | ; is needed.

To run benchmark.
./benchmarks "Simple benchmark"

```