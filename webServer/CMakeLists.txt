cmake_minimum_required(VERSION 3.10)

#set the project name and version
project(webmonitoring VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#debug print
message("started compilation")

# this one is important
SET(CMAKE_SYSTEM_NAME Linux)
#this one not so much
SET(CMAKE_SYSTEM_VERSION 1)

#comment below two lines to run in linux environment
# specify the cross compiler
#SET(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)

# where is the target environment 
#SET(CMAKE_FIND_ROOT_PATH /home/nithin/gcc-linaro-7.5.0-2019.12-x86_64_armeb-linux-gnueabihf/bin/armeb-linux-gnueabihf-g++)

# search for programs in the build host directories
#SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# for libraries and headers in the target directories
#SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
#SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(SRC_FILES src/main.cpp src/networking/bindingsocket.cpp src/networking/listeningsocket.cpp src/networking/socket.cpp src/server/server.cpp src/testingsocket.cpp)

#build the executables
add_executable(webmonitoring ${SRC_FILES})

#include the header files
target_include_directories(webmonitoring PUBLIC ${CMAKE_SOURCE_DIR}/inc)

