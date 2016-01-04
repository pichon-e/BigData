cmake_minimum_required (VERSION 2.6)

set(PROJECT_NAME LandySalasy)
set(SRCS_EXT .cpp)

# Déclaration du projet en premier
project(${PROJECT_NAME})

if(MSVC)
elseif (CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "-W -Wall -Wextre -Werror")
endif(MSVC)

include_directories("./includes/")

# Génération de la list des fichier sources

file (GLOB_RECURSE SOURCES sources/*)
source_group(sources FILES ${SOURCES})

file (GLOB_RECURSE INCLUDES includes/*)
source_group(includes FILES ${INCLUDES})

# Déclaration de l'éxecutable
add_executable(${PROJECT_NAME} ${SOURCES} ${INCLUDES})
set(EXECUTABLE_OUTPUT ${CMAKE_SOURCE_DIR})