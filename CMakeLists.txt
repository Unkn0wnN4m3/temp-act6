cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(pico-pantalla C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(pico-pantalla pico-pantalla.c ssd1306.c ssd1306.h font.h)

# pico_enable_stdio_usb(pico-pantalla 0)
# pico_enable_stdio_uart(pico-pantalla 0)

pico_add_extra_outputs(pico-pantalla)

target_link_libraries(pico-pantalla pico_stdlib hardware_i2c)
