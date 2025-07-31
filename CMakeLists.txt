cmake_minimum_required(VERSION 3.16)
project(SFML3App)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # for clangd/LSP in Neovim

# Find SFML 3 (note: the module names are case-sensitive)
find_package(SFML 3.0 REQUIRED COMPONENTS Graphics Window System)

# Add executable
add_executable(sfml3_app main.cpp)

# Link modern SFML 3 targets
target_link_libraries(sfml3_app PRIVATE SFML::Graphics SFML::Window SFML::System)

