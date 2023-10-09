# http://www.linux-magazin.de/Heft-Abo/Ausgaben/2007/02/Mal-ausspannen

set(PROJECT_NAME libnoise)

include_directories(noise)

set(libSrcs ${libSrcs}
    noisegen.cpp
    latlon.cpp

    model/line.cpp
    model/plane.cpp
    model/sphere.cpp
    model/cylinder.cpp

    module/abs.cpp
    module/add.cpp
    module/billow.cpp
    module/blend.cpp
    module/cache.cpp
    module/ceil.cpp
    module/checkerboard.cpp
    module/clamp.cpp
    module/const.cpp
    module/curve.cpp
    module/cylinders.cpp
    module/displace.cpp
    module/exponent.cpp
    module/floor.cpp
    module/invert.cpp
    module/max.cpp
    module/min.cpp
    module/modulebase.cpp
    module/multiply.cpp
    module/perlin.cpp
    module/power.cpp
    module/ridgedmulti.cpp
    module/rotatepoint.cpp
    module/scalebias.cpp
    module/scalepoint.cpp
    module/select.cpp
    module/spheres.cpp
    module/terrace.cpp
    module/translatepoint.cpp
    module/turbulence.cpp
    module/voronoi.cpp
)

IF(BUILD_SHARED_LIBS AND WIN32)
    set(libSrcs ${libSrcs} win32/dllmain.cpp)
ENDIF()

add_library( noise ${LIBNOISE_LIBRARY_TYPE} ${libSrcs} )

# this value is set in the root CMakeLists.txt
set_target_properties( noise PROPERTIES LIBNOISE_VERSION ${LIBNOISE_VERSION} )

if(BUILD_SHARED_LIBS)
    target_compile_definitions( noise PRIVATE NOISE_BUILD_DLL)
else()
    target_compile_definitions( noise PUBLIC NOISE_STATIC)
endif()


set_target_properties( noise PROPERTIES OUTPUT_NAME "noise" )

# I would like to see more projects using these defaults
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
	message(STATUS "noiseutils - using optimized compile settings with all warnings enabled")
	add_compile_options(-Wall -ansi -pedantic -O3)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
	message(STATUS "noiseutils - using optimized compile settings with all warnings enabled")
	add_compile_options(/Wall /Ox)
endif()

# install include files into /include
install( DIRECTORY "${PROJECT_SOURCE_DIR}/src/noise"
		DESTINATION "${CMAKE_INSTALL_PREFIX}/include" )

# install dynamic libraries (.dll or .so) into /bin
install( TARGETS noise DESTINATION ${LIBNOISE_DESTINATION} )
