#include <catch2/catch.hpp>
#include <task_01.hpp>
#include <vector>
#include <cstdlib>

TEST_CASE("test_task_01")
{
    {
        std::vector<int> input = {1, 2};
        std::vector<char> packed;
        std::vector<int> unpacked;
        auto last = instar::pack(input.begin(), input.end(), std::back_insert_iterator<std::vector<char>>(packed));
        
        CHECK(packed.size() == 1);
        instar::unpack(packed.begin(), packed.end(), std::back_insert_iterator<std::vector<int>>(unpacked));
        CHECK(unpacked == input);
    }
    {
        std::vector<int> input = {14, 15};
        std::vector<char> packed;
        std::vector<int> unpacked;
        instar::pack(input.begin(), input.end(), std::back_insert_iterator<std::vector<char>>(packed));
        CHECK(packed.size() == 1);
        instar::unpack(packed.begin(), packed.end(), std::back_insert_iterator<std::vector<int>>(unpacked));
        CHECK(unpacked == input);
    }
    {
        std::vector<int> input;
        std::vector<char> packed;
        std::vector<int> unpacked;
        for (auto _ = 500000; _--;)
            input.push_back(rand() % 16);
        instar::pack(input.begin(), input.end(), std::back_insert_iterator<std::vector<char>>(packed));
        CHECK(packed.size() <= input.size());
        instar::unpack(packed.begin(), packed.end(), std::back_insert_iterator<std::vector<int>>(unpacked));
        CHECK(unpacked == input);
    }
}