add_library(MAX548X INTERFACE)

target_sources(MAX548X INTERFACE ${CMAKE_CURRENT_LIST_DIR}/MAX548X.cpp)

target_include_directories(MAX548X INTERFACE ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(MAX548X INTERFACE pico_stdlib hardware_spi)