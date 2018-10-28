project(PluginInterface)
cmake_minimum_required(VERSION 3.2)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "-std=c++11 -Ofast -march=native")

add_library(my_plugin SHARED ./src/plugin.cpp)
target_include_directories(my_plugin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(my_interface SHARED ./src/IVRPluginInfo.cpp)
target_link_libraries(my_interface ${CMAKE_DL_LIBS})
target_include_directories(my_interface PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

#add_executable(main ./src/main.cpp)
#target_link_libraries(main my_plugin)

add_executable(naim ./src/main2.cpp)
target_link_libraries(naim my_interface ${CMAKE_DL_LIBS})
