#include "catch2/catch_all.hpp"
#include "cs1/task1.cpp"

TEST_CASE("reverse() throws when no list is passed")
{
    CHECK_THROWS_AS(reverse<int>(nullptr, 10), std::invalid_argument);
}

TEST_CASE("reverse() doesn't do anything when nodes count is 0")
{
    Node a('A');
    Node b('B');
    Node c('C');
    Node d('D');
    Node e('E');
    Node f('F');

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;

    reverse(&a, 0);

    CHECK(a.next == &b);
    CHECK(b.next == &c);
    CHECK(c.next == &d);
    CHECK(d.next == &e);
    CHECK(e.next == &f);
}

TEST_CASE("reverse() throws when node count is greater than size")
{
    Node a('A');
    Node b('B');
    Node c('C');
    Node d('D');
    Node e('E');
    Node f('F');

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;

    CHECK_THROWS_AS(reverse(&a, 10), std::invalid_argument);
}

TEST_CASE("reverse() correctly reverses")
{
    Node a('A');
    Node b('B');
    Node c('C');
    Node d('D');
    Node e('E');
    Node f('F');

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;

    SECTION("First node to last")
    {
        Node<char> *result = reverse(&a, 6);

        CHECK(a.next == nullptr);
        CHECK(b.next == &a);
        CHECK(c.next == &b);
        CHECK(d.next == &c);
        CHECK(e.next == &d);
        CHECK(f.next == &e);
    }

    SECTION("First node to middle node")
    {
        reverse(&a, 3);

        CHECK(a.next == &d);
        CHECK(b.next == &a);
        CHECK(c.next == &b);
        CHECK(d.next == &e);
        CHECK(e.next == &f);
    }

    SECTION("Middle node to middle node")
    {
        Node<char> *result = reverse(&b, 3);

        CHECK(result == &d);
        CHECK(b.next == &e);
        CHECK(c.next == &b);
        CHECK(d.next == &c);
        CHECK(e.next == &f);
    }

    SECTION("Middle node to last")
    {
        reverse(&b, 5);

        CHECK(b.next == nullptr);
        CHECK(c.next == &b);
        CHECK(d.next == &c);
        CHECK(e.next == &d);
        CHECK(f.next == &e);
    }
}

TEST_CASE("reverseSublists() throws when interval is invalid")
{
    Interval interval1{0, 1};
    Interval interval2{2, 4};
    interval1.next = &interval2;
    Interval interval3{5, 1000};
    interval2.next = &interval3;

    Node list1(11);
    Node list2(7);
    Node list3(3);
    list1.next = &list2;
    list2.next = &list3;

    CHECK_THROWS_AS(reverseSublists(&list1, &interval1), std::invalid_argument);
}

TEST_CASE("reverseSublists reverses correctly example from task")
{
    Interval interval1{1, 3};
    Interval interval2{2, 5};
    interval1.next = &interval2;
    Interval interval3{5, 6};
    interval2.next = &interval3;

    Node list1(11);
    Node list2(4);
    Node list3(3);
    Node list4(7);
    Node list5(13);
    Node list6(4);
    Node list7(5);
    list1.next = &list2;
    list2.next = &list3;
    list3.next = &list4;
    list4.next = &list5;
    list5.next = &list6;
    list6.next = &list7;

    reverseSublists(&list1, &interval1);

    CHECK(list1.next == &list4);  // 11 - 7
    CHECK(list2.next == &list7);  // 4 - 5
    CHECK(list3.next == nullptr); // 3 - null
    CHECK(list4.next == &list6);  // 7 - 4
    CHECK(list5.next == &list2);  // 13 - 4
    CHECK(list6.next == &list5);  // 4 - 13
    CHECK(list7.next == &list3);  // 5 - 3
}

TEST_CASE("reverseSublists reverses corectly full list")
{
    Interval interval1{0, 6};

    Node list1(11);
    Node list2(4);
    Node list3(3);
    Node list4(7);
    Node list5(13);
    Node list6(4);
    Node list7(5);
    list1.next = &list2;
    list2.next = &list3;
    list3.next = &list4;
    list4.next = &list5;
    list5.next = &list6;
    list6.next = &list7;

    reverseSublists(&list1, &interval1);

    CHECK(list1.next == nullptr);
    CHECK(list2.next == &list1);
    CHECK(list3.next == &list2);
    CHECK(list4.next == &list3);
    CHECK(list5.next == &list4);
    CHECK(list6.next == &list5);
    CHECK(list7.next == &list6);
}
