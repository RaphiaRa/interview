#include <catch2/catch.hpp>
#include <task_02.hpp>
#include <cstdlib>
#include <list>

static std::list<void *> leaks;

class TestPacket : public instar::Packet
{
public:
    void *operator new(std::size_t size)
    {
        void *p = ::operator new(size);
        leaks.push_back(p);
        return p;
    }

    void operator delete(void *p)
    {
        leaks.remove(p);
        ::operator delete(p);
    }
};

TEST_CASE("test_task_02")
{
    {
        instar::Dispatcher dispatcher;
        dispatcher.dispatch(new TestPacket);

        // Wait until all packets are freed or timeout is reached
        for(auto _ = 50; _--;) 
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            if (leaks.empty())
                break;
        }
        CHECK(leaks.empty());
    }
}