#include <catch2/catch.hpp>
#include <task_01.hpp>
#include <vector>
#include <cstdlib>
#include <iterator>

TEST_CASE("test_task_01")
{
    {
        std::vector<int> input = {1, 2};
        std::vector<char> packed;
        std::vector<int> unpacked;
        instar::pack(input.begin(), input.end(), std::back_insert_iterator<std::vector<char>>(packed));
        {
            INFO("Packed size must be 1");
            CHECK(packed.size() == 1);
        }
        instar::unpack(packed.begin(), packed.end(), std::back_insert_iterator<std::vector<int>>(unpacked));
        {
            INFO("Unpacked vector must equal input vector");
            CHECK(unpacked == input);
        }
    }
    {
        std::vector<int> input = {14, 15};
        std::vector<char> packed;
        std::vector<int> unpacked;
        instar::pack(input.begin(), input.end(), std::back_insert_iterator<std::vector<char>>(packed));
        {
            INFO("Packed size must be 1");
            CHECK(packed.size() == 1);
        }
        instar::unpack(packed.begin(), packed.end(), std::back_insert_iterator<std::vector<int>>(unpacked));
        {
            INFO("Unpacked vector must equal input vector");
            CHECK(unpacked == input);
        }
    }
    {
        std::vector<int> input;
        std::vector<char> packed;
        std::vector<int> unpacked;
        for (auto _ = 1000; _--;)
            input.push_back(rand() % 16);
        instar::pack(input.begin(), input.end(), std::back_insert_iterator<std::vector<char>>(packed));
        {
            INFO("Packed size must be <= half of input size");
            CHECK(packed.size() <= (input.size() / 2));
        }
        instar::unpack(packed.begin(), packed.end(), std::back_insert_iterator<std::vector<int>>(unpacked));
        {
            INFO("Unpacked vector must equal input vector");
            CHECK(unpacked == input);
        }
    }
}
