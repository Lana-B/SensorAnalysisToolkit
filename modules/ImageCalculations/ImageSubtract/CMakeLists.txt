#CMakeList for src dir


cmake_minimum_required(VERSION 2.8.8)
#Add source headers
set(SOURCE_FILES include/stkImageSubtract.hxx)
#Add headers
set(INCLUDE_FILES include/stkImageSubtract.h)
message( STATUS "Source files: ${SOURCE_FILES}" )
#Add library
add_library( stkImageSubtract SHARED ${SOURCE_FILES} ${INCLUDE_FILES} )

set_target_properties(stkImageSubtract PROPERTIES LINKER_LANGUAGE CXX)

