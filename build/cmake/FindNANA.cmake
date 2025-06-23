########################################################################
# CMake module for finding nana GUI library
#
# The following variables will be defined:
#
#  NANA_FOUND
#  NANA_INCLUDE_DIR
#  NANA_LIBRARY
#
if(WIN32)
find_path(NANA_INCLUDE_DIR
  NAMES nana/config.hpp
  PATHS
   "C:/Tools/local/nana/include"
   "C:/Program Files/nana/include"
   "C:/nana/include"
  NO_DEFAULT_PATH)

find_library(NANA_LIBRARY
  NAMES libnana.a
  PATHS
   "C:/Tools/local/nana/lib"
   "C:/Program Files/nana/lib"
   "C:/nana/lib"
  NO_DEFAULT_PATH)
else()
  find_path(NANA_INCLUDE_DIR
    NAMES nana/config.hpp
    PATHS
      /usr/include
      /usr/local/include
      /opt/local/include
      /opt/include
    NO_DEFAULT_PATH)
  
  find_library(NANA_LIBRARY
    NAMES libnana.a
    PATHS
      /usr/lib
      /usr/lib/x86_64-linux-gnu
      /usr/local/lib
      /opt/local/lib
      /opt/lib
   NO_DEFAULT_PATH)
endif()

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(NANA DEFAULT_MSG NANA_LIBRARY NANA_INCLUDE_DIR)
