cmake_minimum_required(VERSION 3.13)

# Set the Pico SDK path
set(PICO_SDK_PATH "/home/vboxuser/pico/pico-sdk")


# Include the Pico SDK
include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)


# Project definition
project(my_first_vscode_pico)


# Initialize the SDK
pico_sdk_init()


# Add your executable
add_executable(${PROJECT_NAME} src/main.cpp)


# Link with Pico standard library
target_link_libraries(${PROJECT_NAME} pico_stdlib)


# Enable USB serial output (for printf)
pico_enable_stdio_usb(${PROJECT_NAME} 1)


# Disable UART serial (unless you need it)
pico_enable_stdio_uart(${PROJECT_NAME} 0)


# Generate UF2, BIN, HEX files
pico_add_extra_outputs(${PROJECT_NAME})