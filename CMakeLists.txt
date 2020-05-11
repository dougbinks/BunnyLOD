cmake_minimum_required( VERSION 2.8 )

project( BunnyLOD )

find_package( OpenGL REQUIRED )

include_directories( "glfw/include" )
include_directories( ${OPENGL_INCLUDE_DIRS} )

set( GLFW_BUILD_EXAMPLES OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_BUILD_TESTS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_BUILD_INSTALL OFF CACHE BOOL  "GLFW lib only" )

add_subdirectory( glfw )

if( WIN32 )
    SET( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup" )
endif()
if( UNIX )
    SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14" )
endif()
if( APPLE )
    SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++" )
endif()

set( BunnyLOD-SRC
     main.cpp
	 bunnygut.cpp
	 progmesh.cpp
	 progmesh.h
	 rabdata.cpp
	 rabdata.h
     linalg.h
     glutil.h
     geometric.h
     misc.h
     )

     
add_executable( BunnyLOD ${BunnyLOD-SRC} )
target_link_libraries( BunnyLOD ${OPENGL_LIBRARIES} glfw ${GLFW_LIBRARIES} )
if( MSVC )
    if(${CMAKE_VERSION} VERSION_LESS "3.6.0") 
        message( "\n\t[ WARNING ]\n\n\tCMake version lower than 3.6.\n\n\t - Please update CMake and rerun; OR\n\t - Manually set 'BunnyLOD' as StartUp Project in Visual Studio.\n" )
    else()
        set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT BunnyLOD )
    endif()
endif()
