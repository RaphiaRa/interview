#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <ctime>
#include <cstdlib>

struct MyListener : Catch::TestEventListenerBase
{
    using TestEventListenerBase::TestEventListenerBase; // inherit constructor

    void testRunStarting(Catch::TestRunInfo const &testRunInfo) override
    {
        srand(time(NULL));
        (void)(testRunInfo);
    }

    void testRunEnded(Catch::TestRunStats const &testRunStats) override
    {
        (void)(testRunStats);
    }
};

CATCH_REGISTER_LISTENER(MyListener)