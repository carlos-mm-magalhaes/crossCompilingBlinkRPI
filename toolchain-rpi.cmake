# CMake-identifier of the target platform to build for
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_VERSION 1)
# CMake-identifier of the target architecture to build for
# set(CMAKE_SYSTEM_PROCESSOR armv6)

# Define the cross compiler locations
set(tools ./compilers/cross-pi-gcc-8.3.0-0)
set(CMAKE_C_COMPILER ${tools}/bin/arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER ${tools}/bin/arm-linux-gnueabihf-g++)

add_definitions(-Wall)
