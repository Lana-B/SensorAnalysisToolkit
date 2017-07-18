#CMakeList for src dir

cmake_minimum_required (VERSION 2.8)
set(CMAKE_MACOSX_RPATH 1)

set(ROOT_DIR /Users/lb8075/ROOT64/root/cmake)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} /Users/lb8075/ROOT64/root/cmake/modules)

set(PROJECT_NAME_STR DataConverterImgToROOT)
project(${PROJECT_NAME_STR})


find_package(ROOT COMPONENTS Core MathCore Hist Tree Physics Cling )

find_package(Threads REQUIRED)

add_definitions(-Wall -ansi -Wno-deprecated -pthread -std=c++11)

#-------------------
# set common include folder for module
#-------------------
set(PROJECT_RAW_IO_SOURCE $ENV{HOME}/Documents/Grating/Code/SensorAnalysisToolkit)
set(COMMON_INCLUDES ${PROJECT_RAW_IO_SOURCE}/modules/IO/RawIOImageStack/include ${PROJECT_RAW_IO_SOURCE}/modules/IO/RawIO/include ${PROJECT_RAW_IO_SOURCE}/modules/Base/ImageStack/include ${PROJECT_RAW_IO_SOURCE}/modules/Base/Image/include ${PROJECT_RAW_IO_SOURCE}/modules/ImageCalculations/ImageSum/include ${PROJECT_RAW_IO_SOURCE}/modules/ImageCalculations/ImageDivision/include ${PROJECT_RAW_IO_SOURCE}/modules/Plotting/Histograms/include )

set(STK_LIB_DIR $ENV{HOME}/Documents/Grating/Code/SensorAnalysisToolkit_build/lib/)


include_directories(${COMMON_INCLUDES})
include_directories(${ROOT_INCLUDE_DIRS})

add_executable(${PROJECT_NAME_STR} ${PROJECT_RAW_IO_SOURCE}/examples/DataConverterImgToROOT/DataConverterImgToROOT.cxx)

target_link_libraries(${PROJECT_NAME_STR} ${CMAKE_THREAD_LIBS_INIT})

target_link_libraries( ${PROJECT_NAME_STR} ${ROOT_LIBRARIES})

target_link_libraries(${PROJECT_NAME_STR} ${STK_LIB_DIR}/libstkRawImageStackIO.dylib ${STK_LIB_DIR}/libstkRawIO.dylib ${STK_LIB_DIR}/libstkImageStack.dylib ${STK_LIB_DIR}/libstkImage.dylib ${STK_LIB_DIR}/libstkImageSum.dylib ${STK_LIB_DIR}/libstkImageDivision.dylib ${STK_LIB_DIR}/libstkImageHistogram.dylib )





