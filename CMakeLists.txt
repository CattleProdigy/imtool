cmake_minimum_required(VERSION 2.8)

project(imtool)

add_definitions(-Wall -msse3)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(SRC_DIR src)
set(INC_DIR include)
set(BIN_DIR bin)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem)
find_package(Qt4 REQUIRED)

include_directories(${INC_DIR} ${QT_INCLUDES})

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

file(GLOB SRCS ${SRC_DIR}/*.cpp)
file(GLOB INCS ${INC_DIR}/*.hpp)

QT4_WRAP_CPP(INCS_MOC ${INCS})

add_executable(imtool ${SRCS} ${INCS_MOC})
TARGET_LINK_LIBRARIES(imtool ${QT_LIBRARIES})
