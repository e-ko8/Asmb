# cmake files date ... ... ...



cmake_minimum_required(VERSION 3.10...3.17 FATAL_ERROR)

project(Computestars)


  if(CMAKE_COMPILER_IS_MSVC)
  message(" my compile MSVC ")
  endif()




set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -stdlib=libc++")

#set_property(Computestars PROPERTY CXX_STANDARD 17)

set(FilesStars 
  #LibraryMath/VectorQuaternion.cpp
   Mainsample/FirstMain.cpp
 )


add_executable(Computestars ${FilesStars} )

set_property(TARGET Computestars PROPERTY CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)

target_include_directories(Computestars PUBLIC 
                      LibraryMath/
                        )


add_custom_target(clean-cmake-files
   COMMAND ${CMAKE_COMMAND} -P clean-all.cmake
)

# clean-all.cmake
set(cmake_generated ${CMAKE_BINARY_DIR}/CMakeCache.txt
                    ${CMAKE_BINARY_DIR}/cmake_install.cmake
                    ${CMAKE_BINARY_DIR}/Makefile
                    ${CMAKE_BINARY_DIR}/CMakeFiles
)

foreach(file ${cmake_generated})

  if (EXISTS ${file})
     file(REMOVE_RECURSE ${file})
  endif()

endforeach(file)