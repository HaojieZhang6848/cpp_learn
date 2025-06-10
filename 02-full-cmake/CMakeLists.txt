cmake_minimum_required(VERSION 3.16)
project(YourProject VERSION 1.0 LANGUAGES CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
  
# 引入fmt
find_package(fmt CONFIG REQUIRED)
find_package(boost_filesystem CONFIG REQUIRED)
find_package(boost_json CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

# 添加 include 路径
include_directories(${PROJECT_SOURCE_DIR}/include)

# 添加子目录（源码）
add_subdirectory(src)

# 添加 GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_subdirectory(test)