cmake_minimum_required(VERSION 3.10.2)
include(${CMAKE_SOURCE_DIR}/toolchain-rpi.cmake)
# Name our project
project(Sweep)
# Create a variable that holds the path to our libwiringPi.so file
set(WPI_PATH ./WiringPi/wiringPi)
# Add the local ‘include’ directory and the wiringPi directory to grab headers
include_directories(include ${WPI_PATH})
# Actually find the wiringPi library object
# find_library(WPI_LIB wiringPi HINTS ${WPI_PATH} NO_CMAKE_FIND_ROOT_PATH)
# Alert the user if we do not find it
#if(NOT WPI_LIB)
# message(FATAL_ERROR “wiringPi library not found”)
#endif()
# Add all the *.c files in our source directory to our executable output
add_executable(${PROJECT_NAME} ${PROJECT_NAME}.c)
# add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp)

# Link the libraries to the executable we just declared

add_subdirectory(include)
add_subdirectory(${WPI_PATH})

target_include_directories(${PROJECT_NAME} 
    PUBLIC include
    PUBLIC ${WPI_PATH}
)

target_link_directories(${PROJECT_NAME} 
    PUBLIC include
    PUBLIC ${WPI_PATH}
)

target_link_libraries(${PROJECT_NAME} 
    ADCDevice
    wiringPi
)