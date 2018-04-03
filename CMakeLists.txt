cmake_minimum_required (VERSION 2.6)

project (affi)

# The version number.

set (affi_VERSION_MAJOR 1)
set (affi_VERSION_MINOR 0)

set(SOURCE_DIR src)
set(INCLUDE_DIR include)
set(INSTALL_DIR install/usr/local/bin)

include_directories(${INCLUDE_DIR})

set(SOURCES ${SOURCE_DIR}/main.c ${SOURCE_DIR}/affichage.c ${SOURCE_DIR}/calcul.c ${SOURCE_DIR}/read_file.c ${SOURCE_DIR}/read_key.c )
set(HEADER_FILES ${INCLUDE_DIR}/affichage.h ${INCLUDE_DIR}/calcul.h ${INCLUDE_DIR}/read_file.h ${INCLUDE_DIR}/read_key.h)

add_definitions(-DDEBUG_L1=1)

add_executable(affi ${SOURCES} ${HEADER_FILES})
set(EXECUTABLE_OUTPUT_PATH ${INSTALL_DIR})