#include <spdlog/spdlog.h>

namespace spdlog_demo
{
    void spdlog_demo()
    {
        spdlog::info("Hello, this is a demo of spdlog!");
        spdlog::warn("This is a warning message.");
        spdlog::error("This is an error message.");
        spdlog::debug("This is a debug message, useful for developers.");
        spdlog::critical("This is a critical message, indicating a serious error.");
        
    }
}