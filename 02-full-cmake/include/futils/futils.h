#pragma once
#include <fstream>
#include <string>

namespace futils
{
    inline bool writeFile(const std::string &path, const std::string &content)
    {
        std::ofstream ofs(path, std::ios::out | std::ios::trunc);
        return ofs ? (ofs << content, true) : false;
    }

    inline std::string readFile(const std::string &path)
    {
        std::ifstream ifs(path, std::ios::in);
        if (!ifs)
        {
            return {};
        }
        std::string content((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
        return content;
    }
}
