#include "catch2/catch_all.hpp"
#include "cs1/task3.cpp"

TEST_CASE("readAndDelete() returns true for an empty word")
{
    std::stack<char> st;
    CHECK(readAndDelete(st, ""));
}

TEST_CASE("readAndDelete() returns true when word can be read")
{
    std::stack<char> st;
    st.push('m');
    st.push('o');
    st.push('o');
    st.push('f');
    st.push('m');

    bool result = readAndDelete(st, "mom");

    CHECK(result);
    CHECK(st.top() == 'f');
    st.pop();
    CHECK(st.top() == 'o');
}

TEST_CASE("readAndDelete() returns false when word can be read")
{
    std::stack<char> st;
    st.push('y');
    st.push('a');
    st.push('d');
    st.push('c');
    st.push('c');

    bool result = readAndDelete(st, "car");

    CHECK_FALSE(result);
    CHECK(st.top() == 'c');
    st.pop();
    CHECK(st.top() == 'd');
    st.pop();
    CHECK(st.top() == 'y');
}
