set(HEADERS
    TEImage.h
    TEImagePNG.h)
set(SOURCES
    TEImagePNG.cpp)
target_sources(TECore PUBLIC ${HEADERS} PRIVATE ${SOURCES} CMakeLists.txt)

tengine_sourcegroup_add()
