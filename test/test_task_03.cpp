#include <catch2/catch.hpp>
#include <task_03.hpp>
#include <cstdlib>
#include <list>

TEST_CASE("test_task_03")
{
    {
        instar::Base base;
        INFO("getMsg() must return \"My name is Base\" if a reference to an Base object ist passed")
        CHECK(instar::getMsg(base) == "My name is Base");
    }
    {
        instar::Banana banana;
        INFO("getMsg() must return \"My name is Banana\" if a reference to an Banana object ist passed")
        CHECK(instar::getMsg(banana) == "My name is Banana");
    }
    {
        instar::Apple apple;
        INFO("getMsg() must return \"My name is Apple\" if a reference to an Apple object ist passed")
        CHECK(instar::getMsg(apple) == "My name is Apple");
    }
}