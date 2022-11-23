cmake_minimum_required(VERSION 3.14)
project(DerivativeCalc)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  expression_tree_test
  expression_tree_test.cpp
  ExpressionTree.cpp
)
target_link_libraries(
  expression_tree_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(expression_tree_test)
