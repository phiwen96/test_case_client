file (GLOB HEADER_LIST ../include/*.hpp)
file (GLOB SOURCE_LIST *.cpp)
add_executable (${PROJECT_NAME} ${SOURCE_LIST} ${HEADER_LIST})


target_link_libraries(${PROJECT_NAME} PRIVATE ph::network ${Boost_LIBRARIES})
target_include_directories (${PROJECT_NAME} PRIVATE ../include ph::network ${Boost_INCLUDE_DIRS})