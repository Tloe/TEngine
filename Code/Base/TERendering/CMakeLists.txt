add_library(TERendering)

tengine_sourcegroup_init()

add_subdirectory(Context)
add_subdirectory(Renderer)
add_subdirectory(SceneGraph)

tengine_sourcegroup_done()

target_link_libraries(TERendering
    PUBLIC
        TEPlatform
        CONAN_PKG::glew
        CONAN_PKG::opengl
    PRIVATE
        TECore)

 target_include_directories(TERendering
    PUBLIC
        Context
        Renderer
        Renderer/CommonResources
        Renderer/DX11
        Renderer/OpenGL
        SceneGraph)

set_target_properties(TERendering PROPERTIES FOLDER "0. TELibs")
