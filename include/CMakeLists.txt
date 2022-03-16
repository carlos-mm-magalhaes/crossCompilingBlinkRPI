cmake_minimum_required(VERSION 3.10.2)
# add all the *.c files as sources
FILE(GLOB SRC_FILES *.cpp)
# make this output a shared library (with .so output)
add_library(ADCDevice STATIC ${SRC_FILES})