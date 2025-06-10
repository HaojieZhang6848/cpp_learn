#include <boost/json.hpp>
#include <fmt/core.h>

namespace boost_json_demo
{

    void boost_json_demo()
    {
        using namespace boost;
        using namespace std;
        
        json::object jv;
        jv["name"] = "Alice";
        jv["age"] = 30;
        jv["city"] = "Wonderland";
        jv["is_student"] = false;

        string json_str = json::serialize(jv);
        fmt::print("Boost JSON example: {}\n", json_str);

        // Example of parsing JSON
        json_str = R"({"name": "Bob", "age": 25, "city": "Builderland", "is_student": true})";
        json::value parsed_json = json::parse(json_str);
        const json::object& parsed_obj = parsed_json.as_object();
        fmt::print("Parsed JSON: name = {}, age = {}, city = {}, is_student = {}\n",
                   string(parsed_obj.at("name").as_string()),
                   parsed_obj.at("age").as_int64(),
                   string(parsed_obj.at("city").as_string()),
                   parsed_obj.at("is_student").as_bool());
    }
}