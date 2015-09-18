cmake_minimum_required(VERSION 3.3)
project(catrpg)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11  -D__NO_INLINE__")
set(EXEC_NAME "catrpg")
# Detect and add SFML
set(CMAKE_MODULE_PATH "C:/Users/smart/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
set(SFML_ROOT "C:/Users/smart/SFML") # You will probably have to change this
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR} ${PROJECT_SOURCE_DIR})
set(SOURCE_FILES main.cpp Game.cpp Game.h)
add_executable(${EXEC_NAME}  ${SOURCE_FILES})
target_link_libraries(${EXEC_NAME} ${SFML_LIBRARIES})
target_link_libraries(${EXEC_NAME} -static-libgcc)
target_link_libraries(${EXEC_NAME} -static-libstdc++)

INSTALL(DIRECTORY ${CMAKE_SOURCE_DIR}/resources/ DESTINATION ${CMAKE_BINARY_DIR}/resources)
INSTALL(DIRECTORY ${CMAKE_SOURCE_DIR}/dll/ DESTINATION ${CMAKE_BINARY_DIR}/)