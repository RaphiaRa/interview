/** task_01.hpp
 * Task:
 * Implement the pack() and unpack() function.
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
     * into a range of k/2 chars (Thus reducing the necesary memory space)
     *@remark You can assume that k is even
     * Example 1:
     * std::vector<int> in = {3, 10};
     * std::vector<char> packed;
     * pack(in.begin(), in.end(), std::back_insert_iterator<std::vector<char>>(packet));
     * // now, packed.size() == 1;
     */
    template <class InIter, class OutIter>
    OutIter pack(InIter begin, InIter end, OutIter out)
    {
        /** Todo **/
    }

    /** unpack
     *@brief Inverse function of pack(), unpacks a range of k chars (that were packed via the pack function) into a range of 2*k integers
     * Example 2:
     * std::vector<int> in = {3, 10};
     * std::vector<char> packed;
     * pack(in.begin(), in.end(), std::back_insert_iterator<std::vector<char>>(packet));
     * std::vector<int> unpacked;
     * unpack(packed.begin(), packed.end(), std::back_insert_iterator<std::vector<char>>(unpacked));
     * // now, in == unpacked
     */
    template <class InIter, class OutIter>
    OutIter unpack(InIter begin, InIter end, OutIter out)
    {
        /** Todo **/
    }
}
#endif