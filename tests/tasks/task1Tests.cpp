#include "catch2/catch_all.hpp"
#include "tasks/task1.cpp"

TEST_CASE("sumOfBigNumbers() throws when one of the numbers is nullptr")
{
    Node a{5};
    CHECK_THROWS_AS(sumOfBigNumbers(nullptr, &a), std::invalid_argument);
    CHECK_THROWS_AS(sumOfBigNumbers(&a, nullptr), std::invalid_argument);
}

TEST_CASE("sumOfBigNumbers() sums equal lenght numbers right")
{
    Node first1{1};
    Node first2{3};
    first1.next = &first2;
    Node second1{2};
    Node second2{4};
    second1.next = &second2;

    Node *result = sumOfBigNumbers(&first1, &second1);

    CHECK(result->value == 3);
    CHECK(result->next->value == 7);

    deleteNodes(result);
}

TEST_CASE("sumOfBigNumbers() sums equal lenght numbers right when carry")
{
    Node first1{3};
    Node first2{1};
    first1.next = &first2;
    Node second1{0};
    Node second2{9};
    second1.next = &second2;

    Node *result = sumOfBigNumbers(&first1, &second1);

    CHECK(result->value == 3);
    CHECK(result->next->value == 0);
    CHECK(result->next->next->value == 1);

    deleteNodes(result);
}

TEST_CASE("sumOfBigNumbers() sums different lenght numbers right")
{
    SECTION("First longer")
    {
        Node first1{1};
        Node first2{0};
        Node first3{1};
        first1.next = &first2;
        first2.next = &first3;
        Node second1{2};
        Node second2{2};
        second1.next = &second2;

        Node *result = sumOfBigNumbers(&first1, &second1);

        CHECK(result->value == 3);
        CHECK(result->next->value == 2);
        CHECK(result->next->next->value == 1);

        deleteNodes(result);
    }

    SECTION("Second longer")
    {
        Node first1{2};
        Node first2{1};
        first1.next = &first2;
        Node second1{7};
        Node second2{0};
        Node second3{2};
        second1.next = &second2;
        second2.next = &second3;

        Node *result = sumOfBigNumbers(&first1, &second1);

        CHECK(result->value == 9);
        CHECK(result->next->value == 1);
        CHECK(result->next->next->value == 2);

        deleteNodes(result);
    }
}

TEST_CASE("sumOfBigNumbers() sums different lenght numbers right with carry")
{
    SECTION("First longer")
    {
        Node first1{1};
        Node first2{0};
        Node first3{1};
        first1.next = &first2;
        first2.next = &first3;
        Node second1{9};
        Node second2{9};
        second1.next = &second2;

        Node *result = sumOfBigNumbers(&first1, &second1);

        CHECK(result->value == 0);
        CHECK(result->next->value == 0);
        CHECK(result->next->next->value == 2);

        deleteNodes(result);
    }

    SECTION("Second longer")
    {
        Node first1{3};
        Node first2{1};
        first1.next = &first2;
        Node second1{7};
        Node second2{0};
        Node second3{2};
        second1.next = &second2;
        second2.next = &second3;

        Node *result = sumOfBigNumbers(&first1, &second1);

        CHECK(result->value == 0);
        CHECK(result->next->value == 2);
        CHECK(result->next->next->value == 2);

        deleteNodes(result);
    }
}
