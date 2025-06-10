#include <iostream>
#include <fmt_demo/fmt_demo.h>
#include <boost_json_demo/boost_json_demo.h>
#include <spdlog_demo/spdlog_demo.h>
#include <spdlog/spdlog.h>

int main() {
    spdlog::info("Starting the demo applications...");
    fmt_demo::fmt_demo();
    boost_json_demo::boost_json_demo();
    spdlog_demo::spdlog_demo();

    spdlog::info("Demo applications completed successfully.");
    return 0;
}