cmake_minimum_required(VERSION 3.10)
project(aquarium)

# Définit la version du standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(PROTOBUF_ROOT "${CMAKE_SOURCE_DIR}/../lib/protobuf")

set(PROTOBUF_ROOT "${CMAKE_SOURCE_DIR}/../lib/protobuf/build/Release")
set(Protobuf_PROTOC_EXECUTABLE "${PROTOBUF_ROOT}/protoc.exe")
set(Protobuf_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/../lib/protobuf/src")
set(Protobuf_LIBRARIES "${PROTOBUF_ROOT}/libprotobuf.lib")

message(STATUS "Using protoc: ${Protobuf_PROTOC_EXECUTABLE}")
message(STATUS "Protobuf include: ${Protobuf_INCLUDE_DIR}")
message(STATUS "Protobuf lib: ${Protobuf_LIBRARIES}")

include_directories(src)

set(SOURCES
    src/main.cpp
    src/poisson.cpp
    src/aquarium.cpp
    src/herbivore.cpp
    src/carnivore.cpp
    src/algue.cpp
)

# Ajoute l’exécutable à construire
add_executable(aquarium ${SOURCES})

target_include_directories(aquarium PRIVATE
    ${CMAKE_BINARY_DIR}
    ${Protobuf_INCLUDE_DIR}
)

target_link_libraries(aquarium PRIVATE
    ${Protobuf_LIBRARIES}
)