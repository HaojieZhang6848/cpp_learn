# 添加可执行文件
# 查找当前目录下所有 cpp 文件
file(GLOB_RECURSE SRC_FILES *.cpp)
add_executable(YourApp ${SRC_FILES})
add_library(YourLib STATIC ${SRC_FILES})

# 可选：设置 include 路径（不全局暴露）
target_include_directories(YourApp PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(YourLib PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(YourApp PRIVATE fmt::fmt Boost::json spdlog::spdlog cpr::cpr)
target_link_libraries(YourLib PRIVATE fmt::fmt Boost::json spdlog::spdlog cpr::cpr)