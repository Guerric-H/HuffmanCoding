cmake_minimum_required(VERSION 3.0.0)
project(HuffmanCoding)

find_package(Qt4 REQUIRED)
SET(CMAKE_AUTOMOC True)

include_directories(headers)

SET(SRCS
    src/graphical/context.cpp
    src/graphical/mainwindow.cpp
    src/graphical/graphicTree.cpp
    src/graphical/graphicEncoding.cpp
    src/graphical/graphicDecoding.cpp
    src/tree_node/node.cpp
    src/tree_node/tree.cpp
    src/encoding/encoding.cpp
    src/decoding/decoding.cpp
)

SET(HEADERS
    headers/graphical/mainwindow.hpp
    headers/graphical/graphicTree.hpp
    headers/graphical/graphicEncoding.hpp
    headers/graphical/graphicDecoding.hpp
    headers/graphical/context.hpp
    headers/tree_node/tree.hpp
    headers/tree_node/node.hpp
    headers/encoding/encoding.hpp
    headers/decoding/decoding.hpp
)

add_executable(main ${SRCS} ${HEADERS} main/main.cpp)
target_link_libraries(main Qt4::QtCore Qt4::QtGui)