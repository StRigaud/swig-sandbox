cmake_minimum_required(VERSION 3.20)

project(cle)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra -Wno-unused-parameter -fPIC")

# find opencl
find_package(OpenCL REQUIRED)
if(OpenCL_FOUND)
    include_directories(${OpenCL_INCLUDE_DIR})
    if(APPLE)
        set(OpenCL_CLHPP_HEADERS ${OpenCL_INCLUDE_DIR}/opencl/opencl.hpp)
    else()
        set(OpenCL_CLHPP_HEADERS ${OpenCL_INCLUDE_DIR}/CL/opencl.hpp)
    endif()
    if(NOT EXISTS ${OpenCL_CLHPP_HEADERS})
        message(WARNING "WARNING: OpenCL-CLHPP is required for a stable install of CLIc Library.")
        set(USE_PROJECT_CLHPP TRUE)
    endif()
endif()

# Create main and link to liba
add_library(${PROJECT_NAME} clesperanto.cpp cleBuffer.cpp cleGPU.cpp clePlatformManager.cpp cleDeviceManager.cpp cleContextManager.cpp cleCommandQueueManager.cpp)

target_link_libraries(${PROJECT_NAME} OpenCL::OpenCL)

# Set up public headers for swig-example
set_target_properties(${PROJECT_NAME} PROPERTIES 
        PUBLIC_HEADER "clic.h" 
        PUBLIC_HEADER "clesperanto.h" 
        PUBLIC_HEADER "cleBuffer.h"
        PUBLIC_HEADER "cleGPU.h"
        PUBLIC_HEADER "clePlatformManager.h"
        PUBLIC_HEADER "cleDeviceManager.h"
        PUBLIC_HEADER "cleContextManager.h"
        PUBLIC_HEADER "cleCommandQueueManager.h"
        PUBLIC_HEADER "cleOperations.h")

# Add install target
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static
        PUBLIC_HEADER DESTINATION include)

# Add swig subdirectory
add_subdirectory(swig)
