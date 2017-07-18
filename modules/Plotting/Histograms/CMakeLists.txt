#CMakeList for src dir

find_package(ROOT COMPONENTS Core MathCore Hist Tree Physics Cling )

#Add source headers
set(SOURCE_FILES include/stkImageHistogram.hxx)
#Add headers
set(INCLUDE_FILES include/stkImageHistogram.h )
message( STATUS "Source files: ${SOURCE_FILES}" )

include_directories(${ROOT_INCLUDE_DIRS})
message( STATUS "ROOT Include dir: ${ROOT_INCLUDE_DIRS}" )
message( STATUS "ROOT Dir dir: ${ROOT_LIBRARIES}" )


#Add library
add_library( stkImageHistogram SHARED ${SOURCE_FILES} ${INCLUDE_FILES} )

target_link_libraries(stkImageHistogram ${TEST_LIB_DIR}/libstkRawIO.dylib ${TEST_LIB_DIR}/libstkImage.dylib ${ROOT_LIBRARIES} )

set_target_properties(stkImageHistogram PROPERTIES LINKER_LANGUAGE CXX)


