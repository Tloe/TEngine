set(HEADERS
    TEResource.h
    TEResourceHandle.h
    TEResourceManager.h
    TECrypto.h)
set(SOURCES
    TEResource.cpp)

target_sources(TECore PUBLIC ${HEADERS} PRIVATE ${SOURCES} CMakeLists.txt)

tengine_sourcegroup_add()