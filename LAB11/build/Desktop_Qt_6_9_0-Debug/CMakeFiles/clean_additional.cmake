# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/LAB11_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/LAB11_autogen.dir/ParseCache.txt"
  "LAB11_autogen"
  )
endif()
