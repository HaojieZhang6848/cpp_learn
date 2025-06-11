#include <futils/futils.h>
#include <random>
#include <fmt/core.h>

namespace futils_demo
{
    std::string random_string(size_t length);

    
    void futils_demo()
    {
        auto file_name = fmt::format("/tmp/futils_demo_{}.txt", random_string(8));
        auto content = fmt::format("This is a demo file created by futils_demo. Random string: {}", random_string(12));
        if (futils::writeFile(file_name, content))
        {
            fmt::print("File '{}' created successfully with content:\n{}\n", file_name, content);
        }
        else
        {
            fmt::print("Failed to create file '{}'.\n", file_name);
            return;
        }

        auto read_content = futils::readFile(file_name);
        if (!read_content.empty())
        {
            fmt::print("Content read from file '{}':\n{}\n", file_name, read_content);
        }
        else
        {
            fmt::print("Failed to read content from file '{}'.\n", file_name);
        }
    }

    std::string random_string(size_t length)
    {
        static const std::string chars =
            "abcdefghijklmnopqrstuvwxyz"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "0123456789";
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, chars.size() - 1);

        std::string result;
        for (size_t i = 0; i < length; ++i)
        {
            result += chars[dist(gen)];
        }
        return result;
    }
}