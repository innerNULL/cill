# file: CMakeLists.txt
# date: 2021-02-01


enable_testing()



add_executable(cill_tests test.cpp)
target_link_libraries(cill_tests PRIVATE ${googletest})

add_test(NAME CILL_TEST COMMAND ./test/cill_test)


