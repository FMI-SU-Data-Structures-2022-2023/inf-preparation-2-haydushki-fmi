#include "catch2/catch_all.hpp"
#include "cs2/task1.cpp"

TEST_CASE("rotateSublists() throws when list is nullptr")
{
    Interval interval1{0, 1};
    CHECK_THROWS_AS(rotateSublists<int>(nullptr, &interval1), std::invalid_argument);
}

TEST_CASE("rotateSublists() throws when interval is invalid")
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

    CHECK_THROWS_AS(rotateSublists(&list1, &interval1), std::invalid_argument);
}

TEST_CASE("rotateSublists() rotates correctly example from task")
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

    rotateSublists(&list1, &interval1);

    CHECK(list1.next == &list4);  // 11 - 7
    CHECK(list2.next == &list3);  // 4 - 3
    CHECK(list3.next == &list7);  // 3 - 5
    CHECK(list4.next == &list6);  // 7 - 4
    CHECK(list5.next == nullptr); // 13 - nullptr
    CHECK(list6.next == &list2);  // 4 - 4
    CHECK(list7.next == &list5);  // 5 - 13
}

TEST_CASE("rotateSublists() rotates correctly first 2 elements")
{
    Interval interval1{0, 1};

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

    rotateSublists(&list1, &interval1);

    CHECK(list1.next == &list3); // 11 - 3
    CHECK(list2.next == &list1); // 4 - 11
    CHECK(list3.next == &list4); // 3 - 5
}

TEST_CASE("rotateSublists() rotates correctly last 2 elements")
{
    Interval interval1{5, 6};

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

    rotateSublists(&list1, &interval1);

    CHECK(list5.next == &list7);  // 13 - 5
    CHECK(list6.next == nullptr); // 4 - nullptr
    CHECK(list7.next == &list6);  // 5 - 4
}

// TODO: add more tests
