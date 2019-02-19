cmake_minimum_required(VERSION 3.7)
project(magenta)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE INCLUDE src/*.h)
file(GLOB_RECURSE SRC src/*.cc src/*.cpp src/*.c)
file(GLOB_RECURSE RES res/*.*)

add_executable(magenta ${INCLUDE} ${SRC})

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
pkg_check_modules(WEBKIT2GTK REQUIRED webkit2gtk-4.0)

include_directories(${GTK3_INCLUDE_DIRS} ${WEBKIT2GTK_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS} ${WEBKIT2GTK_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER} ${WEBKIT2GTK_CFLAGS_OTHER})

target_link_libraries(magenta ${GTK3_LIBRARIES} ${WEBKIT2GTK_LIBRARIES})
file(COPY ${RES} DESTINATION "${CMAKE_BINARY_DIR}/res/")
