#include <catch2/catch.hpp>
#include <task_03.hpp>
#include <cstdlib>
#include <list>


TEST_CASE("test_task_03")
{
    {
        instar::Base base;
        CHECK(instar::getMsg(base) == "My name is Base");
        instar::Banana banana;
        CHECK(instar::getMsg(banana) == "My name is Banana");
        instar::Apple apple;
        CHECK(instar::getMsg(apple) == "My name is Apple");
    }
}