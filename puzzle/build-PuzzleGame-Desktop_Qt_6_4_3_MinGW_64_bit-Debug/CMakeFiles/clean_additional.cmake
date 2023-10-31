# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\PuzzleGame_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\PuzzleGame_autogen.dir\\ParseCache.txt"
  "PuzzleGame_autogen"
  )
endif()
