cmake_minimum_required(VERSION 3.10)

project(pdfParser)

add_executable(pdfParser parse.cpp)

find_library(podofo podofo)

find_library(fontconfig fontconfig)
find_library(freetype freetype)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

find_package(ZLIB REQUIRED) # ZLIB_INCLUDE_DIR, ZLIB_LIBRARIES
include_directories("${ZLIB_INCLUDE_DIR}")
target_link_libraries(pdfParser PUBLIC ${podofo} ${fontconfig} ${freetype} ${ZLIB_LIBRARIES})
