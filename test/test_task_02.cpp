#include <catch2/catch.hpp>
#include <task_02.hpp>
#include <cstdlib>
#include <list>
#include <mutex>
#include <atomic>

static std::list<void *> leaks;
static std::mutex mtx;

class TestPacket : public instar::Work
{
public:
    TestPacket(std::atomic<int> &count) : count_(count) {}
    void process() override
    {
        instar::Work::process();
        count_++;
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

private:
    std::atomic<int> &count_;
};

TEST_CASE("test_task_02")
{
    {
        instar::Dispatcher dispatcher;
        std::atomic<int> counta(0);
        dispatcher.dispatch(new TestPacket(counta));
        std::atomic<int> countb(0);
        dispatcher.dispatch(new TestPacket(countb));
        std::atomic<int> countc(0);
        dispatcher.dispatch(new TestPacket(countc));

        // Wait until process was called 500 times, or timeout was reached
        for (auto _ = 600; _--;)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            if (counta.load() == 500 && countb.load() == 500 && countc.load() == 500)
                break;
        }
        {
            INFO("Packet::process must run 500 times")
            CHECK(counta.load() == 500);
        }
        {
            INFO("Packet::process must run 500 times")
            CHECK(countb.load() == 500);
        }
        {
            INFO("Packet::process must run 500 times")
            CHECK(countc.load() == 500);
        }
        {
            INFO("Memory must be freed")
            CHECK(leaks.empty());
        }
    }
}