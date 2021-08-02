# Include python
find_package(Python3 REQUIRED Development NumPy)
if(Python3_FOUND)
  include_directories(${Python3_INCLUDE_DIRS})
endif()
if(Python3_NumPy_FOUND)
  include_directories(Python3_NumPy_INCLUDE_DIRS)
  message(${Python3_NumPy_INCLUDE_DIRS})
endif()

set(CMAKE_SWIG_FLAGS "")
set_source_files_properties(../${PROJECT_NAME}.i PROPERTIES CPLUSPLUS ON)
include_directories(../..)

# Add swig module
swig_add_library(pyclesperanto LANGUAGE python SOURCES ../${PROJECT_NAME}.i)
swig_link_libraries(pyclesperanto ${PROJECT_NAME} OpenCL::OpenCL Python3::Python Python3::NumPy )

# Files to install with Python
set(PYTHON_INSTALL_FILES
        ${CMAKE_CURRENT_BINARY_DIR}/pyclesperanto.py
        ${CMAKE_CURRENT_BINARY_DIR}/_pyclesperanto.so)

# Configure setup.py and copy to output directory
set(SETUP_PY_IN ${CMAKE_CURRENT_SOURCE_DIR}/setup.py.in)
set(SETUP_PY_OUT ${CMAKE_CURRENT_BINARY_DIR}/setup.py)
configure_file(${SETUP_PY_IN} ${SETUP_PY_OUT})

# # Declare install target for python
# install(TARGETS pyclesperanto
#        COMMAND "${PYTHON_EXECUTABLE} setup.py"
#        COMPONENT swig-python)

# Install target to call setup.py
add_custom_target(install-python
        DEPENDS _pyclesperanto
        COMMAND python ${SETUP_PY_OUT} install)