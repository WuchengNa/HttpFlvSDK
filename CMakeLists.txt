cmake_minimum_required(VERSION 3.12)
project(HttpFlvSDK)

set(CMAKE_CXX_STANDARD 11)

# Add your source files here
set(SOURCES
    sample/server/server_demo.cpp
)

# Add your header files here
#set(HEADERS )

# Add any additional libraries or dependencies here
#set(LIBRARIES)

# Set the output directory for the binary
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add the executable target
add_executable(${PROJECT_NAME} ${SOURCES} )

# Link any libraries or dependencies
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})