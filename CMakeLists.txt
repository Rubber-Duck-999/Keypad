cmake_minimum_required(VERSION 3.13)

set(NAME pico-boilerplate)

include(pico_sdk_import.cmake)
include(pimoroni_pico_import.cmake)

# Gooey boilerplate
project(${NAME} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(libraries/pico_rgb_keypad/pico_rgb_keypad)

add_executable(${NAME}
    main.cpp
)

# Add pico_stdlib library which aggregates commonly used features
# Pull in pico libraries that we need
target_link_libraries(${NAME} pico_stdlib pico_rgb_keypad)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(${NAME})