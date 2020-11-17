cmake_minimum_required(VERSION 3.0.0)
project(HuffmanCoding)

find_package(Qt4 REQUIRED)
SET(CMAKE_AUTOMOC True)

include_directory(headers)


SET(SRCS
    src/graphical/display.cpp
    src/tree_node/node.cpp
    src/tree_node/tree.cpp
)

SET(HEADERS
    graphical/display.hh
    tree_node/tree.hh
    tree_node/node.hh
)

add_executable(part1 ${SRCS} ${HEADERS} main/part1.cpp)
target_link_libraries(part1 Qt4::QtCore Qt4::QtGui)

