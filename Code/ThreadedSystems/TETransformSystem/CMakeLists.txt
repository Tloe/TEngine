add_library(TETransformSystem "")

set(HEADERS
    TETransformSystem.h
    TETransformObject.h
    TETransformScene.h)
set(SOURCES
    TETransformSystem.cpp
    TETransformObject.cpp
    TETransformScene.cpp)

target_sources(TETransformSystem PUBLIC ${HEADERS} PRIVATE ${SOURCES})

tengine_sourcegroup_init()
tengine_sourcegroup_add()
tengine_sourcegroup_done()

target_include_directories(TETransformSystem
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(TETransformSystem PRIVATE TEngine)

set_target_properties(TETransformSystem PROPERTIES FOLDER "2. TEngine Systems")
