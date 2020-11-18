cmake_minimum_required(VERSION 3.0.0)
project(HuffmanCoding)

find_package(Qt4 REQUIRED)
SET(CMAKE_AUTOMOC True)

include_directories(headers)

SET(SRCS
    src/graphical/display.cpp
    src/tree_node/node.cpp
    src/tree_node/tree.cpp
)

SET(HEADERS
    headers/graphical/display.hh
    headers/tree_node/tree.hh
    headers/tree_node/node.hh
)

add_executable(part1 ${SRCS} ${HEADERS} main/part1.cpp)
target_link_libraries(part1 Qt4::QtCore Qt4::QtGui)

