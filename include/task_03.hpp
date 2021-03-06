/** task_03.hpp
 * Task:
 * Finish the implementation of the classes Base, Apple & Banana such that
 * the function getMsg(const Base&) returns
 * "My name is Base" if a reference to a Base object is passed
 * "My name is Apple" if a reference to an Apple object is passed
 * "My name is Banana" if a reference to a Banana obhect is passed
 */

#ifndef INSTAR_TASK_03_HPP
#define INSTAR_TASK_03_HPP
#include <string>

namespace instar
{
    /** Todo: Adapt Base to make it inheritable **/
    class Base
    {
        public:
        std::string msg() const { return "My name is Base"; }
    };

    class Apple : public Base
    {
        /** Todo **/
    };

    class Banana : public Base
    {
        /** Todo **/  
    };

    /** Don't change anything from this line on **/
    std::string getMsg(const Base& base) {return base.msg();}
}
#endif