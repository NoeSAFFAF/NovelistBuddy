cmake_minimum_required(VERSION 3.10)

# Set the toolchain file for Vcpkg
# if (DEFINED ENV{VCPKG_TOOLCHAIN_FILE})
#     set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_TOOLCHAIN_FILE})
# else ()
#    message(FATAL_ERROR "Environment variable VCPKG_TOOLCHAIN_FILE is not set.")
# endif ()

project(NovelistBuddy)

find_package(CURL CONFIG REQUIRED)

file(GLOB_RECURSE SOURCES src/*.cpp src/*.h)
add_executable(NovelistBuddy ${SOURCES})

target_compile_features(oai PRIVATE cxx_std_17)

target_link_libraries(NovelistBuddy PRIVATE CURL::libcurl)
#target_link_libraries(NovelistBuddy PRIVATE ${CURL_LIBRARIES})

install(TARGETS NovelistBuddy DESTINATION lib)

target_include_directories(NovelistBuddy PRIVATE ${CURL_INCLUDE_DIRS})
target_include_directories(NovelistBuddy PRIVATE src)