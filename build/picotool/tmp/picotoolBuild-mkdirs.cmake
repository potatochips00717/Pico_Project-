# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/vboxuser/pico_workspace/projects/my_first_vscode_pico/build/_deps/picotool-src"
  "/home/vboxuser/pico_workspace/projects/my_first_vscode_pico/build/_deps/picotool-build"
  "/home/vboxuser/pico_workspace/projects/my_first_vscode_pico/build/_deps"
  "/home/vboxuser/pico_workspace/projects/my_first_vscode_pico/build/picotool/tmp"
  "/home/vboxuser/pico_workspace/projects/my_first_vscode_pico/build/picotool/src/picotoolBuild-stamp"
  "/home/vboxuser/pico_workspace/projects/my_first_vscode_pico/build/picotool/src"
  "/home/vboxuser/pico_workspace/projects/my_first_vscode_pico/build/picotool/src/picotoolBuild-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/vboxuser/pico_workspace/projects/my_first_vscode_pico/build/picotool/src/picotoolBuild-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/vboxuser/pico_workspace/projects/my_first_vscode_pico/build/picotool/src/picotoolBuild-stamp${cfgdir}") # cfgdir has leading slash
endif()
