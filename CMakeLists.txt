cmake_minimum_required(VERSION 3.10)
project(aquarium LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Protobuf REQUIRED)
find_package(absl REQUIRED)

set(PROTO_FILE "${CMAKE_CURRENT_SOURCE_DIR}/aquarium.proto")
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILE})

add_library(protos STATIC ${PROTO_SRCS} ${PROTO_HDRS})
target_include_directories(protos PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(protos PUBLIC
    ${Protobuf_LIBRARIES}
    absl::base
    absl::strings
    absl::log_internal_check_op
    absl::log_severity
    absl::log_internal_message
    absl::raw_logging_internal
)

file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(aquarium_exec ${SOURCES})

target_link_libraries(aquarium_exec PRIVATE 
    protos
    absl::base
    absl::strings
    absl::log_internal_check_op
    absl::log_severity
    absl::log_internal_message
    absl::raw_logging_internal
    absl::status
)