# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "AntiPirateGUI_autogen"
  "CMakeFiles/AntiPirateGUI_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/AntiPirateGUI_autogen.dir/ParseCache.txt"
  )
endif()
