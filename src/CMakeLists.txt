file (GLOB HEADER_LIST ../include/*.hpp)
file (GLOB SOURCE_LIST *.cpp)
add_executable (${PROJECT_NAME} ${SOURCE_LIST} ${HEADER_LIST})



target_include_directories (${PROJECT_NAME} PRIVATE ../include)