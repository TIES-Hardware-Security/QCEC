# Install script for directory: /Users/chao/Projects/qcec_final/qcec/extern/qfr/extern/pybind11_json

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Library/Developer/CommandLineTools/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/pybind11_json" TYPE FILE FILES "/Users/chao/Projects/qcec_final/qcec/extern/qfr/extern/pybind11_json/include/pybind11_json/pybind11_json.hpp")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/pybind11_json" TYPE FILE FILES
    "/Users/chao/Projects/qcec_final/qcec/build/src/extern/qfr/mqt/qfr/extern/pybind11_json/CMakeFiles/pybind11_jsonConfig.cmake"
    "/Users/chao/Projects/qcec_final/qcec/build/src/extern/qfr/mqt/qfr/extern/pybind11_json/pybind11_jsonConfigVersion.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/pybind11_json/pybind11_jsonTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/pybind11_json/pybind11_jsonTargets.cmake"
         "/Users/chao/Projects/qcec_final/qcec/build/src/extern/qfr/mqt/qfr/extern/pybind11_json/CMakeFiles/Export/b09025fd913bb59bd77bece4188c0aa6/pybind11_jsonTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/pybind11_json/pybind11_jsonTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/pybind11_json/pybind11_jsonTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/pybind11_json" TYPE FILE FILES "/Users/chao/Projects/qcec_final/qcec/build/src/extern/qfr/mqt/qfr/extern/pybind11_json/CMakeFiles/Export/b09025fd913bb59bd77bece4188c0aa6/pybind11_jsonTargets.cmake")
endif()

