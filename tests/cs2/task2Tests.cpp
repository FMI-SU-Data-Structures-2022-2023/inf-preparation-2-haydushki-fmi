#include "catch2/catch_all.hpp"
#include "cs2/task2.cpp"

TEST_CASE("makeTotal() returns false when list is a nullptr")
{
    CHECK_FALSE(makeTotal(nullptr));
}

TEST_CASE("makeTotal() returns false when list items are less than 2")
{
    Node a(5);

    CHECK_FALSE(makeTotal(&a));
}

TEST_CASE("makeTotal() returns true when list is continuous")
{
    Node a(2);
    Node b(1);
    Node c(2);
    Node d(3);
    Node e(4);
    Node f(3);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;

    CHECK(makeTotal(&a));
}

TEST_CASE("makeTotal() returns false when list is not continuous nor continuous")
{
    Node a(1);
    Node b(2);
    Node c(3);
    Node d(4);
    Node e(2);
    Node f(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;

    CHECK_FALSE(makeTotal(&a));
    CHECK(a.next == &c);
    CHECK(b.next == nullptr);
    CHECK(c.next == &f);
}
