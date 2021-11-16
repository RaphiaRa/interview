/** task_01.hpp
 * Task:
 * Assume that begin, end range consist of int values in the range [0, 15]
 */

#ifndef INSTAR_TASK_01_HPP
#define INSTAR_TASK_01_HPP
#include <vector>
#include <iterator>
#include <cassert>
namespace instar
{
    /** pack
     *@brief Packs a range of k integers, where each int is in the range [0,15],
     * into a range k/2 chars (Thus reducing the necesary memory space)
     * 
     * Example 1:
     * std::vector<int> in = {3, 10};
     * std::vector<char> packed;
     * pack(in.begin(), in.end(), std::back_insert_iterator<std::vector<char>>(packet));
     * // packed is now a vector of size 1
     */
    template <class InIter, class OutIter>
    OutIter pack(InIter begin, InIter end, OutIter out)
    {
        /** Todo **/
    }

    /** unpack
     *@brief Unpacks a range of k chars into a range of 2*k integers
     */
    template <class InIter, class OutIter>
    OutIter unpack(InIter begin, InIter end, OutIter out)
    {
        /** Todo **/
    }
}
#endif