#include "catch2/catch_all.hpp"
#include "cs1/task2.cpp"

TEST_CASE("hasBalance() works as expected")
{
    SECTION("previous is nullptr")
    {
        Node a(1);
        Node b(4);

        CHECK_FALSE(hasBalance<int>(nullptr, &a, &b));
    }

    SECTION("current is nullptr")
    {
        Node a(1);
        Node b(4);

        CHECK_FALSE(hasBalance<int>(&a, nullptr, &b));
    }

    SECTION("next is nullptr")
    {
        Node a(1);
        Node b(4);

        CHECK_FALSE(hasBalance<int>(&a, &b, nullptr));
    }

    SECTION("Not balanced")
    {
        Node a(-9);
        Node b(-3);
        Node c(4);

        CHECK_FALSE(hasBalance(&a, &b, &c));
    }

    SECTION("Balanced")
    {
        Node a(-9);
        Node b(-5);
        Node c(4);
        CHECK(hasBalance(&a, &b, &c));
    }
}

TEST_CASE("makeTotal() returns false when list doesn't exist")
{
    CHECK_FALSE(makeTotal<int>(nullptr));
}

TEST_CASE("makeTotal() returns false when list items are less than 3")
{
    Node a(5);
    Node b(6);
    a.next = &b;

    CHECK_FALSE(makeTotal(&a));
}

TEST_CASE("makeTotal() returns true when list is balanced")
{
    Node a(1);
    Node b(-4);
    Node c(-5);
    Node d(-1);
    Node e(4);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    CHECK(makeTotal(&a));
}

TEST_CASE("makeTotal() returns false when list is not balanced nor unbalanced")
{
    Node a(10);
    Node b(5);
    Node c(-5);
    Node d(-15);
    Node e(2);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    CHECK_FALSE(makeTotal(&a));
    CHECK(a.next == &d);
    CHECK(d.next == &e);
}
