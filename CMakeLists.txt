cmake_minimum_required(VERSION 3.13)

# 工程名称
project(order_snapshot)
project(unit_test)

# 设置
set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(SYSTEM "BookSystem/include")

# 指定当前目录下的源文件，保存到<ALL_SRCS>变量中
aux_source_directory(BookSystem/src ALL_SRCS)
aux_source_directory(UnitTest ALL_TEST)

set(UNIT_TEST ./UnitTest)
set(PROJECT_DIR ./BookSystem/src)

set(googleTestDir ./googletest/googletest)
#Add the google test subdirectory
add_subdirectory(${googleTestDir})
#include googletest/include dir
include_directories(${googleTestDir}/googletest/include)
#include the googlemock/include dir
include_directories(${googleTestDir}/googlemock/include)

#include_directories(${COMMON_INCLUDES})
file(GLOB SRC_FILES ${PROJECT_DIR}/*.cpp)
file(GLOB LINKED_SRC ${PROJECT_DIR}/*.cpp)
list(FILTER LINKED_SRC EXCLUDE REGEX ".*main.cpp$")

file(GLOB TEST_SRC_FILES ${UNIT_TEST}/*.cpp)
#add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES} ${SRC_FILES})

# 编译源码生成目标
add_executable(order-snapshot ${SRC_FILES})

add_executable(UNIT_TEST ${TEST_SRC_FILES} ${LINKED_SRC} UnitTest/SymbolTest.cpp UnitTest/OrderPoolTest.cpp UnitTest/SymbolPoolTest.cpp UnitTest/OrderWrapTest.cpp)

# Link with GoogleTest
target_link_libraries(UNIT_TEST gtest gtest_main)
#Link with GoogleMock
target_link_libraries(UNIT_TEST gmock gmock_main)
