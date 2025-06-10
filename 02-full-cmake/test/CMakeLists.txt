enable_testing()

file(GLOB_RECURSE SRC_FILES *.cpp)
add_executable(YourTests ${SRC_FILES})
target_include_directories(YourTests PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(YourTests gtest gtest_main YourLib)

add_test(NAME YourTests COMMAND YourTests)