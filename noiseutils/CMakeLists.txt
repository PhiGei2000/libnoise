set(PROJECT_NAME libnoiseutils)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS YES CACHE BOOL "Export all symbols")
set(libSrcs ${libSrcs}
	noiseutils.cpp
)
add_library(noiseutils ${LIBNOISE_LIBRARY_TYPE} ${libSrcs})

set_target_properties(noiseutils PROPERTIES LIBNOISE_VERSION ${LIBNOISE_VERSION})

target_link_libraries(noiseutils noise)

# I would like to see more projects using these defaults
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
	message(STATUS "noiseutils - using optimized compile settings with all warnings enabled")
	add_compile_options(-Wall -ansi -pedantic -O3)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
	message(STATUS "noiseutils - using optimized compile settings with all warnings enabled")
	add_compile_options(/Wall /Ox)
endif()

# Where to look for noise headers
target_include_directories( noiseutils PRIVATE ${PROJECT_SOURCE_DIR}/src )

# install include files into /include
install( FILES "${PROJECT_SOURCE_DIR}/noiseutils/noiseutils.h" 
		DESTINATION "${CMAKE_INSTALL_PREFIX}/include/noise" )

# install dynamic libraries (.dll or .so) into /bin
install( TARGETS noiseutils DESTINATION ${LIBNOISE_DESTINATION} )
