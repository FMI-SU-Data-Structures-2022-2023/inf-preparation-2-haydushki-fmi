#include "catch2/catch_all.hpp"
#include "cs2/task3.cpp"
#include <stack>

TEST_CASE("readAndDeleteQueue() returns true for an empty word")
{
    std::queue<char> queue;
    CHECK(readAndDeleteQueue(queue, ""));
}

TEST_CASE("readAndDeleteQueue() returns true when word can be read")
{
    std::queue<char> queue;
    queue.push('m');
    queue.push('f');
    queue.push('o');
    queue.push('o');
    queue.push('m');

    bool result = readAndDeleteQueue(queue, "mom");

    CHECK(result);
    CHECK(queue.front() == 'o');
    queue.pop();
    CHECK(queue.front() == 'f');
}

TEST_CASE("readAndDeleteQueue() returns false when word can be read")
{
    std::queue<char> queue;
    queue.push('c');
    queue.push('c');
    queue.push('d');
    queue.push('a');
    queue.push('y');

    bool result = readAndDeleteQueue(queue, "car");

    CHECK_FALSE(result);
    CHECK(queue.front() == 'y');
    queue.pop();
    CHECK(queue.front() == 'd');
    queue.pop();
    CHECK(queue.front() == 'c');
}
