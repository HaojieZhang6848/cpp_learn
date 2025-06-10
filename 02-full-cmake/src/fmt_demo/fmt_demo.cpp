#include "foo/foo.h"
#include "fmt/core.h"

namespace fmt_demo
{

    void fmt_demo()
    {
        // Example usage of fmt library
        int a = 5;
        int b = 10;
        int add = foo_add(a, b);
        int sub = foo_subtract(a, b);

        fmt::print("Formatted output: foo_add({}, {}) = {}, foo_subtract({}, {}) = {}\n", a, b, add, a, b, sub);

        std::string result = fmt::format("This is a formatted string with values: {}, {}", a, b);
        fmt::print("{}\n", result);
    }
}