include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2)

FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(engine_test input_manager_test.cpp)

target_link_libraries(engine_test PRIVATE GTest::GTest SDL3 SDL3_ttf engine)

include(GoogleTest)
gtest_discover_tests(engine_test)
