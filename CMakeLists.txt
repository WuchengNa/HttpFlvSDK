cmake_minimum_required(VERSION 3.15)

project(HttpFlvSDK)
message("configure project name:${PROJECT_NAME}")

#set include dir
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/src)

#collect src file
file(GLOB_RECURSE SRC_FILE "${CMAKE_SOURCE_DIR}/src/*/*.cpp")

#cxx flags
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

#set link dir
link_directories(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/3rd/lib)

# Add the executable target
add_library(${PROJECT_NAME} ${SRC_FILE})

# Link any libraries or dependencies
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBRARIES})

# do something after build
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMENT "Copying ..."
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT_NAME}> ${OUTPUT_DIR}
)
