cmake_minimum_required(VERSION 3.5)
project(ml)

find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message(STATUS "C++14 support has been enabled by default.")

####################################
set(LI_INSTALL_LOCATION "D:/Yolsa/assets")
#set(LI_INSTALL_LOCATION "/home/yol/Yolsa/assets")
set(CMAKE_INSTALL_PREFIX ${LI_INSTALL_LOCATION})

set(LI_OpenCV_INCLUDE_DIRS D:/Yolsa/Android/opencv/x86/mingw/lib/include;D:/Yolsa/Android/opencv/x86/mingw/lib/include/opencv)
set (LI_OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui)
#set(LI_OpenCV_INCLUDE_DIRS ${OpenCV_INCLUDE_DIRS})
#set (LI_OpenCV_LIBS ${OpenCV_LIBS})
include_directories(${LI_OpenCV_INCLUDE_DIRS})
####################################
#message(STATUS "${CMAKE_CURRENT_SOURCE_DIR}: ${OpenCV_LIBS}")
include_directories(${PROJECT_SOURCE_DIR}/../../../3rdparty)
include_directories(${PROJECT_SOURCE_DIR}/src/includes)
include_directories(${PROJECT_SOURCE_DIR}/3rdparty/tiny_dnn_11)
#include_directories(${PROJECT_SOURCE_DIR}/3rdparty/tiny_dnn_14)

set (module_name test_dl)
message(STATUS "${module_name}")

FILE(GLOB sourcefiles "*.cpp" "*.c")
#FILE(GLOB_RECURSE sourcefiles "src/connectedCompents.cpp")
#target_link_libraries(k ${VISION_BASE} ${LI_OpenCV_LIBS})

#FILE(GLOB sourcefiles "src/*.cpp" "src/*.c")
add_executable(${module_name} ${sourcefiles})
#target_compile_definitions(${module_name} -mbig-obj)
#target_compile_options(${module_name} "-O3")
add_compile_options("-Wall" -O3 )
target_link_libraries(${module_name} ${LI_OpenCV_LIBS})

install (TARGETS ${module_name}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)

#add_subdirectory (dl)
####################################
#include_directories(src)
#include_directories (src/core/interface)
#include_directories (src/core/include)

#include_directories(src/modules/basic)

#include_directories(3rdparty)

#message(STATUS "${CMAKE_CURRENT_SOURCE_DIR}: ${OpenCV_INCLUDE_DIRS}")
#message(STATUS "${CMAKE_CURRENT_BINARY_DIR}: ${OpenCV_INCLUDE_DIRS}")



#SET(EIGEN3_INCLUDE_DIR "$ENV{EIGEN3_INCLUDE_DIR}")
#IF (NOT EIGEN3_INCLUDE_DIR)
#    MESSAGE(FATAL_ERROR "please point the environment variable EIGEN3_INCLUDE_DIR")
#ENDIF ()
#INCLUDE_DIRECTORIES("${EIGEN3_INCLUDE_DIR}")

#FILE(GLOB sourcefiles "src/*.cpp" "src/*.c")
#FILE(GLOB_RECURSE sourcefiles "src/connectedCompents.cpp")
#target_link_libraries(k ${VISION_BASE} ${LI_OpenCV_LIBS})

#FILE(GLOB sourcefiles "src/*.cpp" "src/*.c")
#add_executable(${module_name} ${sourcefiles})
#target_link_libraries(${module_name} ${VISION_BASE} ${LI_OpenCV_LIBS})


#message(STATUS ${VISION_BASE})

#link_directories(${CMAKE_BINARY_DIR}/3rdparty/test)
#find_library(CUR_LIB NAMES vision_test
#         HINTS "${CMAKE_BINARY_DIR}/3rdparty/test")


#message(STATUS ${CMAKE_BINARY_DIR})
#SET(CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR}/3rdparty/test)
#
#message(STATUS "!!!!!!!!!!!!!!!!!!!!!!")
#message(STATUS ${CMAKE_PREFIX_PATH})

#target_link_libraries(vision ${CUR_LIB} vision_vp vision_core ${LI_OpenCV_LIBS})
#target_link_libraries(vision ${CMAKE_BINARY_DIR}/3rdparty/test/libvision_test.dll ${VISION_BASE} ${LI_OpenCV_LIBS})


#message(STATUS ${CMAKE_CURRENT_BINARY_DIR})
