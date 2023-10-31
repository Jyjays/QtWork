# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\puzzlegame_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\puzzlegame_autogen.dir\\ParseCache.txt"
  "puzzlegame_autogen"
  )
endif()
