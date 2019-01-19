project(PluginInterface)
cmake_minimum_required(VERSION 3.2)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_AUTOMOC ON) #to get qt plugins to work
set(CMAKE_CXX_FLAGS "-std=c++11 -Ofast -march=native")


find_package(Qt5 COMPONENTS Core Gui)

# simple test example
add_library(q_plugin SHARED examples/q_plugin.cpp)
target_include_directories(q_plugin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(q_plugin Qt5::Core)

add_executable(main ./examples/main.cpp)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(main Qt5::Core Qt5::Gui)

# interface test
add_library(qt_vrdevice_test SHARED examples/qt_example_plugin.cpp)
target_include_directories(qt_vrdevice_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(qt_vrdevice_test Qt5::Core Qt5::Gui) #gui just for qmatrix

add_executable(naim ./examples/main3.cpp)
target_include_directories(naim PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(naim Qt5::Core Qt5::Gui)
