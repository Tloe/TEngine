add_library(TEPhysics)

tengine_sourcegroup_init()

add_subdirectory(Collision)
add_subdirectory(Physics)

tengine_sourcegroup_done()

target_link_libraries(TEPhysics PRIVATE TECore)

target_include_directories(TEPhysics
    PUBLIC
        Collision
        Physics)

set_target_properties(TEPhysics PROPERTIES FOLDER "0. TELibs")
