cmake_minimum_required(VERSION 3.0.0)
project(HuffmanCoding)

find_package(Qt4 REQUIRED)
SET(CMAKE_AUTOMOC True)

include_directories(headers)

SET(SRCS
    src/graphical/display.cpp
    src/tree_node/node.cpp
    src/tree_node/tree.cpp
    src/encoding/encoding.cpp
)

SET(HEADERS
    headers/graphical/display.hpp
    headers/graphical/Context.hpp
    headers/tree_node/tree.hpp
    headers/tree_node/node.hpp
    headers/encoding/encoding.hpp
)

add_executable(part2 ${SRCS} ${HEADERS} main/part2.cpp)
target_link_libraries(part2 Qt4::QtCore Qt4::QtGui)