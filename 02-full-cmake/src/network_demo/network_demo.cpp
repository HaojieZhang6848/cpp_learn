#include <cpr/cpr.h>
#include <spdlog/spdlog.h>

namespace network_demo
{
    void network_demo()
    {
        cpr::Response r = cpr::Get(cpr::Url{"https://httpbin.org/get"});
        spdlog::info("Response status code: {}", r.status_code);
        spdlog::info("Response text: {}", r.text);
    }
}