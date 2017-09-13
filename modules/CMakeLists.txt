#Top level CMakeList for project

#cmake_minimum_required (VERSION 2.8)
#set(CMAKE_MACOSX_RPATH 1)

#set(ROOT_DIR /Users/lb8075/ROOT64/root/cmake)
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} /Users/lb8075/ROOT64/root/cmake/modules)

#project (SensorAnalysisToolKit)

#set(PROJECT_RAW_IO_SOURCE $ENV{HOME}/Documents/Grating/Code/SensorAnalysisToolkit)
#set(TEST_LIB_DIR $ENV{HOME}/Documents/Grating/Code/SensorAnalysisToolkit_build/lib/)

#set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
#set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )

add_subdirectory (${PROJECT_BASE_DIR}/modules/IO/RawIO)
add_subdirectory (${PROJECT_BASE_DIR}/modules/IO/RawIOImageStack)

add_subdirectory (${PROJECT_BASE_DIR}/modules/Base/Image)
add_subdirectory (${PROJECT_BASE_DIR}/modules/Base/ImageStack)

add_subdirectory (${PROJECT_BASE_DIR}/modules/ImageCalculations/ImageSum)
add_subdirectory (${PROJECT_BASE_DIR}/modules/ImageCalculations/ImageDivision)

add_subdirectory (${PROJECT_BASE_DIR}/modules/ImageCalculations/ImageSubtract)
add_subdirectory (${PROJECT_BASE_DIR}/modules/ImageCalculations/ImageSquare)
add_subdirectory (${PROJECT_BASE_DIR}/modules/ImageCalculations/ImageVariance)

add_subdirectory (${PROJECT_BASE_DIR}/modules/Plotting/Histograms)
