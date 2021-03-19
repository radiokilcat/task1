cmake_minimum_required(VERSION 3.5)

project(elvis LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)
FIND_PACKAGE( Boost COMPONENTS program_options filesystem REQUIRED )

INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
add_executable(elvis main.cpp executor.cpp data_container.cpp file_parser.cpp line_container.cpp)
TARGET_LINK_LIBRARIES( elvis LINK_PUBLIC ${Boost_LIBRARIES} Threads::Threads)
