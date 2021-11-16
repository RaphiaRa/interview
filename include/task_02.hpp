/** task_02.hpp
 * Task:
 * Dispatcher::dispatch is used to pass the ownership of a work pointer to different threads
 * but the pointer is not freed.
 * Fix this memory leak by changing only a single line
 */

#ifndef INSTAR_TASK_02_HPP
#define INSTAR_TASK_02_HPP
#include <chrono>
#include <thread>
#include <memory>
namespace instar
{
    class Work
    {
    public:
        virtual ~Work() = default;
        void process()
        {
            // sleep to simulate some blocking work for 0.1 - 0.5 second
            int m = rand() % 400;
            std::this_thread::sleep_for(std::chrono::milliseconds(100 + m));
        }
    };

    class Dispatcher
    {
    public:
        Dispatcher() = default;
        /** dispatch
         * @remark Ownership of p is transferred
         */
        void dispatch(Work *p)
        {
            auto pwork = p;

            /** dispatch should be non blocking, don't wait for threads to return **/
            for (auto _ = 500; _--;)
            {
                std::thread([pwork, &d]()
                            { pwork->process(); })
                    .detach();
            }
        }
    };
}
#endif