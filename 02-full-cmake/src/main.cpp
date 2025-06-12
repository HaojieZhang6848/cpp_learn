#include <iostream>
#include <fmt_demo/fmt_demo.h>
#include <boost_json_demo/boost_json_demo.h>
#include <spdlog_demo/spdlog_demo.h>
#include <spdlog/spdlog.h>
#include <ds_demo/ds_demo.h>
#include <futils_demo/futils_demo.h>
#include <fmt/core.h>
#include <spdlog/version.h>
#include <boost/version.hpp>
#include <network_demo/network_demo.h>

int main()
{
    spdlog::info("Starting the demo applications, dependency versions:");
    spdlog::info("spdlog version: {}.{}.{}",
                 SPDLOG_VER_MAJOR, SPDLOG_VER_MINOR, SPDLOG_VER_PATCH);
    spdlog::info("fmt version: {}.{}.{}",
                 FMT_VERSION / 10000, (FMT_VERSION / 100) % 100, FMT_VERSION % 100);
    spdlog::info("Boost version: {} ({})", BOOST_LIB_VERSION, BOOST_VERSION);

    fmt_demo::fmt_demo();
    boost_json_demo::boost_json_demo();
    spdlog_demo::spdlog_demo();
    ds_demo::ds_demo();
    futils_demo::futils_demo();
    network_demo::network_demo();

    spdlog::info("Demo applications completed successfully.");
    return 0;
}