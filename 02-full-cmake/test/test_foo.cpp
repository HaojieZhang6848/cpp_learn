#include <gtest/gtest.h>
#include <foo/foo.h>
#include <vector>

struct AddTestCase
{
    int a;
    int b;
    int expected;
};

TEST(Foo, Addition)
{
    std::vector<AddTestCase> test_cases = {
        {1, 2, 3},
        {3, 4, 7},
        {10, 20, 30},
        {0, 0, 0},
        {-1, -1, -2},
        {-5, 5, 0}};

    for (const auto &test_case : test_cases)
    {
        EXPECT_EQ(foo_add(test_case.a, test_case.b), test_case.expected);
    }
}

struct SubtractTestCase
{
    int a;
    int b;
    int expected;
};

TEST(Foo, Subtraction)
{
    auto test_cases = {
        SubtractTestCase{5, 3, 2},
        SubtractTestCase{10, 5, 5},
        SubtractTestCase{20, 10, 10}};

    for (const auto &test_case : test_cases)
    {
        EXPECT_EQ(foo_subtract(test_case.a, test_case.b), test_case.expected);
    }
}
