<<<<<<< HEAD
# Install script for directory: /workspaces/yunheyue/yunheyue_final_project

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
=======
# Install script for directory: D:/yunheyue-final-project/yunheyue_final_project

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Hello")
>>>>>>> 68b65cf4e898c04663044459c35fac614b3d884f
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
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

<<<<<<< HEAD
# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

=======
>>>>>>> 68b65cf4e898c04663044459c35fac614b3d884f
# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
<<<<<<< HEAD
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/workspaces/yunheyue/yunheyue_final_project/build/lib/cmake_install.cmake")
  include("/workspaces/yunheyue/yunheyue_final_project/build/src/cmake_install.cmake")

=======
  set(CMAKE_OBJDUMP "D:/MingW64/MinGW64/bin/objdump.exe")
>>>>>>> 68b65cf4e898c04663044459c35fac614b3d884f
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
<<<<<<< HEAD
file(WRITE "/workspaces/yunheyue/yunheyue_final_project/build/${CMAKE_INSTALL_MANIFEST}"
=======
file(WRITE "D:/yunheyue-final-project/yunheyue_final_project/build/${CMAKE_INSTALL_MANIFEST}"
>>>>>>> 68b65cf4e898c04663044459c35fac614b3d884f
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
