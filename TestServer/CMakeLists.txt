
cmake_minimum_required(VERSION 2.6)

project(atuns)

#add_definitions(-DUSE_EPOLL)
#add_definitions(-DHAVE_IOCTL)

include_directories(. ./detail c:/openssl-110/include64)

# Source files to be used in the library
file (GLOB app_SOURCES *.cpp)

set(OPENSSL_ROOT_DIR c:/openssl-110)

find_package(OpenSSL)

if (OPENSSL_FOUND)
    add_executable(atuns ${app_SOURCES})
    target_link_libraries(atuns ../IocpServer/debug/iocp_lib)
else()
    message(SEND_ERROR "no openssl library found")
endif()
