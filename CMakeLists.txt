cmake_minimum_required(VERSION 3.5)# 最小cmake版本3.5
project(AntiPirateGUI LANGUAGES CXX)# 设置工程名为untitled 使用的语言为C++


################################---SETTINGS---#################################

SET(EXECUTABLE_OUTPUT_PATH ".")# 设置可执行文件输出文件夹为当前文件夹
SET(CMAKE_INCLUDE_CURRENT_DIR ON)# CMake自动添加CMAKE_CURRENT_SOURCE_DIR and CMAKE_CURRENT_BINARY_DIR to the include path for each directory.
SET(CMAKE_AUTOUIC ON)# initialize the AUTOUIC property on all the targets
SET(CMAKE_AUTOMOC ON)# initialize the AUTOMOC property on all the targets
SET(CMAKE_AUTORCC ON)# initialize the AUTORCC property on all the targets
SET(CMAKE_CXX_STANDARD 11)# 设置C++编译器标准 11
SET(CMAKE_CXX_STANDARD_REQUIRED ON)# initialize the CXX_STANDARD_REQUIRED property on all targets

option(LINK_SHARED_ZED "Link with the ZED SDK shared executable" ON)# 设置 链接ZED动态库为 ON

if (NOT LINK_SHARED_ZED AND MSVC)# 如果不链接动态库 并且 使用的MSVC编译器（win平台）
    message(FATAL_ERROR "LINK_SHARED_ZED OFF : ZED SDK static libraries not available on Windows")# 在win平台上找不到静态库
endif ()

if (COMMAND cmake_policy)# 设置cmake policy
    cmake_policy(SET CMP0003 OLD)
    cmake_policy(SET CMP0015 OLD)
endif (COMMAND cmake_policy)

IF (NOT WIN32)# 如果是linux平台下
    SET(SPECIAL_OS_LIBS "pthread" "X11")
    add_definitions(-Wno-write-strings -fpermissive)
ENDIF ()

################################---SETTINGS---#################################


################################---FIND PACKAGE, INCLUDE DIRS, LINK DIRS---#################################

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

find_package(ZED 3 REQUIRED)
find_package(OpenCV REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(CUDA ${ZED_CUDA_VERSION} EXACT REQUIRED)


include_directories(${ZED_INCLUDE_DIRS}
        ${OpenCV_INCLUDE_DIRS}
        ${GLEW_INCLUDE_DIRS}
        ${GLUT_INCLUDE_PATH}
        ${CUDA_INCLUDE_DIRS})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Source/Detector
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/UI
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/Tracker
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/DataType
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/Sort)


################################---FIND PACKAGE, INCLUDE DIRS, LINK DIRS---#################################


if (LINK_SHARED_ZED)
    SET(ZED_LIBS ${ZED_LIBRARIES} ${CUDA_CUDA_LIBRARY} ${CUDA_CUDART_LIBRARY})
else ()
    SET(ZED_LIBS ${ZED_STATIC_LIBRARIES} ${CUDA_CUDA_LIBRARY} ${CUDA_LIBRARY})
endif ()

FILE(GLOB_RECURSE SRC_FILES ./Source/*.cpp
        ./Source/*.c
        ./Source/*.h
        ./Source/*.hpp
        ./Source/*.ui)


add_executable(${PROJECT_NAME} ${SRC_FILES})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
        ${SPECIAL_OS_LIBS}
        ${ZED_LIBS}
        ${OpenCV_LIBRARIES}
        ${OPENGL_LIBRARIES}
        ${GLUT_LIBRARY}
        ${GLEW_LIBRARIES})













