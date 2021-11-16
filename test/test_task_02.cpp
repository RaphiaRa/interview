#include <catch2/catch.hpp>
#include <task_02.hpp>
#include <cstdlib>
#include <list>
#include <mutex>
#include <atomic>

static std::list<void *> leaks;
static std::mutex mtx;
static std::atomic<int> count;

class TestPacket : public instar::Work
{
public:
    void process() override
    {
        instar::Work::process();
        count++;
    }

    void *operator new(std::size_t size)
    {
        std::lock_guard<std::mutex> lk(mtx);
        void *p = ::operator new(size);
        leaks.push_back(p);
        return p;
    }

    void operator delete(void *p)
    {
        std::lock_guard<std::mutex> lk(mtx);
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
        for (auto _ = 50; _--;)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            std::lock_guard<std::mutex> lk(mtx);
            if (leaks.empty())
                break;
        }
        CHECK(leaks.empty());
        CHECK(count == 500);
    }
}