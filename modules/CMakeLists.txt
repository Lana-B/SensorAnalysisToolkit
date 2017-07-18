#Top level CMakeList for project

cmake_minimum_required (VERSION 2.8)
set(CMAKE_MACOSX_RPATH 1)

set(ROOT_DIR /Users/lb8075/ROOT64/root/cmake)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} /Users/lb8075/ROOT64/root/cmake/modules)

project (SensorAnalysisToolKit)

#set(PROJECT_RAW_IO_SOURCE $ENV{HOME}/Documents/Grating/Code/SensorAnalysisToolkit)
set(TEST_LIB_DIR $ENV{HOME}/Documents/Grating/Code/SensorAnalysisToolkit_build/lib/)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )

add_subdirectory ($ENV{HOME}/Documents/Grating/Code/SensorAnalysisToolkit/modules/IO/RawIO)
add_subdirectory ($ENV{HOME}/Documents/Grating/Code/SensorAnalysisToolkit/modules/IO/RawIOImageStack)

add_subdirectory ($ENV{HOME}/Documents/Grating/Code/SensorAnalysisToolkit/modules/Base/Image)
add_subdirectory ($ENV{HOME}/Documents/Grating/Code/SensorAnalysisToolkit/modules/Base/ImageStack)

add_subdirectory ($ENV{HOME}/Documents/Grating/Code/SensorAnalysisToolkit/modules/ImageCalculations/ImageSum)
add_subdirectory ($ENV{HOME}/Documents/Grating/Code/SensorAnalysisToolkit/modules/ImageCalculations/ImageDivision)

add_subdirectory ($ENV{HOME}/Documents/Grating/Code/SensorAnalysisToolkit/modules/Plotting/Histograms)