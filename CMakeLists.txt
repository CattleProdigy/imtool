cmake_minimum_required(VERSION 2.8)

project(imtool)

add_definitions(-Wall -msse3)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(SRC_DIR src)
set(INC_DIR include)
set(BIN_DIR bin)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)


find_package(OpenCV COMPONENTS opencv_core;opencv_highgui;opencv_imgproc REQUIRED)
  set(OpenCV_LIBS "opencv_core;opencv_highgui;opencv_imgproc")
  include_directories(${OpenCV_INCLUDE_DIRS})
  
# Boost
find_package(Boost COMPONENTS filesystem REQUIRED)

# Qt
find_package(Qt4 REQUIRED)
  include(${QT_USE_FILE})
  include_directories(${QT_INCLUDES})
  add_definitions(${QT_DEFINITIONS})

# OpenGL
find_package(OpenGL REQUIRED)

file(GLOB SRCS ${SRC_DIR}/*.cpp)
file(GLOB INCS ${INC_DIR}/*.hpp)
include_directories(${INC_DIR})

QT4_WRAP_CPP(INCS_MOC ${INCS})

add_executable(imtool ${SRCS} ${INCS_MOC})
  target_link_libraries(imtool ${OpenCV_LIBS})
  target_link_libraries(imtool ${QT_LIBRARIES})
