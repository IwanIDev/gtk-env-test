set(VCPKG_TARGET_TRIPLET x64-linux)
include(./vcpkg/scripts/buildsystems/vcpkg.cmake)

cmake_minimum_required(VERSION 3.10)

# Project name
project(gtk_env_test)

# Find GTK
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk4)

add_executable(${PROJECT_NAME} src/main.c)

# Include GTK headers
target_include_directories(${PROJECT_NAME} PRIVATE ${GTK_INCLUDE_DIRS})
target_link_directories(${PROJECT_NAME} PRIVATE ${GTK_LIBRARY_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${GTK_LIBRARIES})
