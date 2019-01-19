project(PluginInterface)
cmake_minimum_required(VERSION 3.2)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_AUTOMOC ON) #to get qt plugins to work
set(CMAKE_CXX_FLAGS "-std=c++11 -Ofast -march=native")


find_package(Qt5 COMPONENTS Core Gui)

add_library(ivrdevice_implementation SHARED ./src/VRPluginInfo.cpp)
target_link_libraries(ivrdevice_implementation ${CMAKE_DL_LIBS} Qt5::Core Qt5::Gui)
target_include_directories(ivrdevice_implementation PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(my_plugin SHARED ./examples/example_plugin.cpp)
target_include_directories(my_plugin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(my_plugin Qt5::Core Qt5::Gui)

add_executable(naim ./examples/main2.cpp)
target_link_libraries(naim ivrdevice_implementation ${CMAKE_DL_LIBS} Qt5::Core Qt5::Gui)


#qt plugin
add_library(q_plugin SHARED examples/q_plugin.cpp)
target_include_directories(q_plugin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(q_plugin Qt5::Core)

add_executable(main ./examples/main.cpp)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(main Qt5::Core Qt5::Gui)

