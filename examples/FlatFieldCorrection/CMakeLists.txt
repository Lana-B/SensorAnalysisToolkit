#CMakeList for src dir

cmake_minimum_required(VERSION 2.8.8)
set(CMAKE_MACOSX_RPATH 1)
	
set(ROOT_DIR /Users/lb8075/ROOT64/root)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${ROOT_DIR}/cmake/modules)
MESSAGE(STATUS "Using cmake module path ${CMAKE_MODULE_PATH}")

set(PROJECT_NAME_STR FlatFieldCorrection)
project(${PROJECT_NAME_STR})

set(PROJECT_BASE_DIR /Users/lb8075/Documents/Grating/Code/SensorAnalysisToolkit)

# set(CMAKE_CXX_FLAGS '-std=c++11')

# find_package(ROOT REQUIRED Hist RIO Tree MathCore Gpad Gui )
find_package(ROOT COMPONENTS Core MathCore Hist Tree Physics Cling )

find_package(Threads REQUIRED)
MESSAGE(STATUS "Threads REQUIRED")

# if(CMAKE_COMPILER_IS_GNUCXX)
add_definitions(-Wall -ansi -Wno-deprecated -pthread -std=c++11 -ltbb)
# add_definitions(-Wall -ansi -Wno-deprecated -pthread -std=c++0x)
# endif()
MESSAGE(STATUS "adding definitions")


#-------------------
# set common include folder for module
#-------------------
# set(PROJECT_RAW_IO_SOURCE /Users/lb8075/Documents/Grating/Code/SensorAnalysisToolkit)
set(COMMON_INCLUDES  /usr/local/Cellar/tbb/2017_U7/include/ ${PROJECT_BASE_DIR}/modules/IO/RawIOImageStack/include ${PROJECT_BASE_DIR}/modules/IO/RawIO/include ${PROJECT_BASE_DIR}/modules/Base/ImageStack/include ${PROJECT_BASE_DIR}/modules/Base/Image/include ${PROJECT_BASE_DIR}/modules/ImageCalculations/ImageSum/include ${PROJECT_BASE_DIR}/modules/ImageCalculations/ImageDivision/include ${PROJECT_BASE_DIR}/modules/Plotting/Histograms/include ${PROJECT_BASE_DIR}/modules/ImageCalculations/ImageVariance/include ${PROJECT_BASE_DIR}/modules/ImageCalculations/ImageMask/include ${PROJECT_BASE_DIR}/modules/ImageCalculations/ImageBadPixelAverage/include ${PROJECT_BASE_DIR}/modules/ImageCalculations/ImageMinus/include ${PROJECT_BASE_DIR}/modules/ImageCalculations/ImageResize/include ${PROJECT_BASE_DIR}/modules/ImageCalculations/ImageFlatFieldCorrection/include)
# set(COMMON_INCLUDES ${PROJECT_BASE_DIR}/modules/IO/RawIOImageStack/include ${PROJECT_BASE_DIR}/modules/IO/RawIO/include ${PROJECT_BASE_DIR}/modules/Base/ImageStack/include ${PROJECT_BASE_DIR}/modules/Base/Image/include ${PROJECT_BASE_DIR}/modules/ImageCalculations/ImageSum/include ${PROJECT_BASE_DIR}/modules/ImageCalculations/ImageDivision/include ${PROJECT_BASE_DIR}/modules/Plotting/Histograms/include ${PROJECT_BASE_DIR}/modules/ImageCalculations/ImageVariance/include ${PROJECT_BASE_DIR}/modules/ImageCalculations/ImageMask/include ${PROJECT_BASE_DIR}/modules/ImageCalculations/ImageBadPixelAverage/include ${PROJECT_BASE_DIR}/modules/ImageCalculations/ImageMinus/include ${PROJECT_BASE_DIR}/modules/ImageCalculations/ImageResize/include ${PROJECT_BASE_DIR}/modules/ImageCalculations/ImageFlatFieldCorrection/include)
# set(ROOT_INCLUDE_DIRS /software/root/v6.04.00/include)

# set(PROJECT_RAW_IO_LIB ${PROJECT_BASE_DIR}/../SensorAnalysisToolkit_Build)
set(STK_LIB_DIR /Users/lb8075/Documents/Grating/Code/SensorAnalysisToolkit_Build/lib)
# set(ROOT_INCLUDE_DIRS /Users/lb8075/ROOT64/root/include)
# set(ROOT_LIBRARIES /Users/lb8075/ROOT64/root/lib)

include_directories(${COMMON_INCLUDES})
include_directories(${ROOT_INCLUDE_DIRS})

add_executable(${PROJECT_NAME_STR} ${PROJECT_SOURCE_DIR}/FlatFieldCorrection.cxx)
target_link_libraries(${PROJECT_NAME_STR} ${CMAKE_THREAD_LIBS_INIT})

target_link_libraries( ${PROJECT_NAME_STR} ${ROOT_LIBRARIES})

target_link_libraries(${PROJECT_NAME_STR} ${STK_LIB_DIR}/libstkRawImageStackIO.dylib ${STK_LIB_DIR}/libstkRawIO.dylib ${STK_LIB_DIR}/libstkImageStack.dylib ${STK_LIB_DIR}/libstkImage.dylib ${STK_LIB_DIR}/libstkImageSum.dylib ${STK_LIB_DIR}/libstkImageDivision.dylib ${STK_LIB_DIR}/libstkImageHistogram.dylib ${STK_LIB_DIR}/libstkImageVariance.dylib ${STK_LIB_DIR}/libstkImageMask.dylib ${STK_LIB_DIR}/libstkImageBadPixelAverage.dylib ${STK_LIB_DIR}/libstkImageMinus.dylib ${STK_LIB_DIR}/libstkImageResize.dylib ${STK_LIB_DIR}/libstkImageFlatFieldCorrection.dylib )

target_link_libraries(${PROJECT_NAME_STR} /usr/local/Cellar/tbb/2017_U7/lib/libtbb.dylib /usr/local/Cellar/tbb/2017_U7/lib/libtbbmalloc.dylib)



