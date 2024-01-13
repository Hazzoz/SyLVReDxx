
add_executable(linksearch main.cpp)

if(UNIX)

    add_definitions(-DUNIX)
    add_definitions(-Dunix)
endif(UNIX)

if(WIN32)

    message(FATAL_ERROR "Use of CMake on Windows not currently supported")
endif(WIN32)


target_link_libraries(linksearch
    STLSoft::STLSoft
    WilliamsCRC::WilliamsCRC
    recls::recls
	xTests::xTests.core
)

