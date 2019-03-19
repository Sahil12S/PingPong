cmake_minimum_required(VERSION 3.13)
project(PingPong)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_COMPILER  /usr/bin/g++)
set(CMAKE_C_COMPILER /usr/bin/gcc)

set(SOURCE_FILES main.cpp Bat.h Bat.cpp Ball.h Ball.cpp Engine.h Engine.cpp Draw.cpp Input.cpp Update.cpp HUD.cpp HUD.h)

add_executable(PingPong ${SOURCE_FILES})

set(EXECUTABLE_NAME ${PROJECT_NAME})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.4 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()