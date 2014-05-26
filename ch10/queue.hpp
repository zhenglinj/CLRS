/***************************************************************************
 *  @file       queue.hpp
 *  @author     Alan.W
 *  @date       25  May 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H
#include <vector>
#include <assert.h>

namespace ch10
{

/**
 * @brief The queue class
 *
 * a simple queue using std::vector as the underlying
 * container and iterators as head and tail.
 *
 * check page 235 for detail.
 */
template<typename T>
class queue
{
public:
    using Container = std::vector<T>;
    using Iter      = typename Container::iterator;
    using SizeType  = typename Container::size_type;

    /**
     * @brief default ctor
     * @param size
     */
    explicit queue(std::size_t size):
        c(size + 1), head(c.begin()), tail(c.begin())
    {}

    /**
     * @brief enqueue
     * @param val
     *
     * based on Page 235
     */
    void enqueue(const T& val)
    {
        assert(!full() && "overflow");

        *tail = val;
        tail = increment(tail);
    }

    /**
     * @brief dequeue
     *
     * based on Page 235
     */
    T dequeue()
    {
        assert(!empty() && "underflow");

        T ret = *head;
        head = increment(head);

        return ret;
    }

    /**
     * @brief empty
     */
    bool empty() const
    {
        return head == tail;
    }

    /**
     * @brief full
     */
    bool full ()
    {
        return head == increment(tail) ;
    }

    /**
     * @brief size
     */
    SizeType size() const
    {
        return c.size();
    }

private:
    Container c;
    Iter head;
    Iter tail;

    /**
     * @brief increment
     * @param iter  iterator
     *
     * increment iterator and check if reaches end. go back to begin
     * if true.
     */
    Iter increment( Iter iter)
    {
        ++iter;
        return ( iter != c.end() )?    iter    :   c.begin();
    }
};
}


#endif // QUEUE_H