add_library(TEPlatform)

tengine_sourcegroup_init()

set(HEADERS TEPlatformWindowIncludes.h)

target_sources(TEPlatform PUBLIC ${HEADERS} CMakeLists.txt)

if(UNIX)
    find_package(X11 REQUIRED)
    set(PLATFORM_INCLUDES ${X11_INCLUDE_DIR})
    set(PLATFORM_LIBRARIES ${X11_LIBRARIES} ${X11_Xxf86vm_LIB})
endif()

tengine_sourcegroup_init()

add_subdirectory(InputMapping)
add_subdirectory(Linux)
add_subdirectory(Win)

tengine_sourcegroup_add()
tengine_sourcegroup_done()

target_link_libraries(TEPlatform
    PRIVATE
        ${PLATFORM_LIBRARIES}
        TECore)

target_include_directories(TEPlatform
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        InputMapping
        Linux
        Win)

set_target_properties(TEPlatform PROPERTIES FOLDER "0. TELibs")
