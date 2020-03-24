project(test)

add_subdirectory(googletest)

add_executable(Google_tests_run calculator_test.cpp)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(Google_tests_run gtest gtest_main)

include_directories(../)
target_link_libraries(Google_tests_run Calculator)