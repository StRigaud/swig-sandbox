# Set up swig
find_package(SWIG 4.0 COMPONENTS python)
if(SWIG_FOUND)
  message("SWIG found: ${SWIG_EXECUTABLE}")
  include(${SWIG_USE_FILE})
endif()

# Add subdirectories for each language if desired
option(BUILD_PYTHON "Build Python SWIG module" ON)
if(BUILD_PYTHON)
    add_subdirectory(python)
endif()
