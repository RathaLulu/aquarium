cmake_minimum_required(VERSION 3.10)
project(aquarium LANGUAGES CXX)

# ----------------------------
#  Standard C++
# ----------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# ----------------------------
#  Dossiers include du projet
# ----------------------------
include_directories(src)

# Inclure les headers de Protobuf et Abseil
include_directories("C:/Users/lucas/Documents/code/lib/protobuf/src")
include_directories("C:/Users/lucas/Documents/code/lib/abseil-cpp/")
include_directories(${CMAKE_CURRENT_BINARY_DIR})  # pour les .pb.h générés

# ----------------------------
#  Protobuf (manuel)
# ----------------------------
# Chemins vers ton build de Protobuf 34
set(Protobuf_INCLUDE_DIR "C:/Users/lucas/Documents/code/lib/protobuf/src")
set(Protobuf_LIBRARIES "C:/Users/lucas/Documents/code/lib/protobuf/build/Release/libprotobuf.lib")
set(Protobuf_PROTOC_EXECUTABLE "C:/Users/lucas/Documents/code/lib/protobuf/build/Release/protoc.exe")


# Recherche Protobuf
find_package(Protobuf REQUIRED)

# Inclure les headers Protobuf
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})  # dossiers pour .pb.h générés

# ----------------------------
#  Tous les fichiers .proto
# ----------------------------
file(GLOB PROTO_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.proto")

# Génération automatique des .pb.cc et .pb.h
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})

# ----------------------------
#  Librairie pour les fichiers protobuf générés
# ----------------------------
add_library(protos STATIC ${PROTO_SRCS} ${PROTO_HDRS})
target_include_directories(protos PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(protos PUBLIC ${Protobuf_LIBRARIES})

# ----------------------------
#  Sources principales du projet
# ----------------------------
set(SOURCES
    src/main.cpp
    src/poisson.cpp
    src/aquarium.cpp
    src/herbivore.cpp
    src/carnivore.cpp
    src/algue.cpp
)

# ----------------------------
#  Exécutable final
# ----------------------------
add_executable(aquarium ${SOURCES})
target_link_libraries(aquarium PRIVATE protos)