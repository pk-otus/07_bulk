cmake_minimum_required(VERSION 3.2)

project(bulk_test)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

configure_file(in1.txt in1.txt COPYONLY)
configure_file(in2.txt in2.txt COPYONLY)
configure_file(in3.txt in3.txt COPYONLY)
configure_file(in4.txt in4.txt COPYONLY)
configure_file(in5.txt in5.txt COPYONLY)
configure_file(out1.txt out1.txt COPYONLY)
configure_file(out2.txt out2.txt COPYONLY)
configure_file(out3.txt out3.txt COPYONLY)
configure_file(out4.txt out4.txt COPYONLY)
configure_file(out5.txt out5.txt COPYONLY)

add_executable(bulk_test test_main.cpp ${HEADER_FILES})

set_target_properties(bulk_test PROPERTIES
INCLUDE_DIRECTORIES "${GTEST_INCLUDE_DIRS};${INCLUDE_DIR}"
)

target_link_libraries(bulk_test ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	target_link_libraries(bulk_test pthread)
endif()

add_test(BulkTest1 bulk_test)
add_test(BulkTest2 bulk_test)
add_test(BulkTest3 bulk_test)
add_test(BulkTest4 bulk_test)
add_test(BulkTest5 bulk_test)
