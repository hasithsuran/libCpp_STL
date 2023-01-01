cmake_minimum_required(VERSION 3.5)

set(LIBRARY_NAME "STL_Lib")
set(SOURCE_DIR "src")
set(INCLUDE_DIR "include")

project(${LIBRARY_NAME}
        VERSION 0.0.1
        DESCRIPTION "STL demonstration library"
        LANGUAGES CXX)
set(CMAKE_CXX_FLAGS "-Wall")

list(APPEND SOURCE_FILES
${SOURCE_DIR}/TC_Vector.cpp
${SOURCE_DIR}/TC_Map.cpp
)

ADD_LIBRARY(${LIBRARY_NAME} STATIC ${SOURCE_FILES})
target_include_directories(${LIBRARY_NAME} PRIVATE ${INCLUDE_DIR})
target_compile_features(${LIBRARY_NAME} PRIVATE cxx_std_20)