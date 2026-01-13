# cmake_minimum_required(VERSION 3.13)

# # Set the Pico SDK path
# set(PICO_SDK_PATH "/home/vboxuser/pico/pico-sdk")


# # Include the Pico SDK
# include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)


# # Project definition
# project(my_first_vscode_pico)


# # Initialize the SDK
# pico_sdk_init()


# # Add your executable
# add_executable(${PROJECT_NAME} src/main.cpp)


# # Link with Pico standard library
# target_link_libraries(${PROJECT_NAME} pico_stdlib)


# # Enable USB serial output (for printf)
# pico_enable_stdio_usb(${PROJECT_NAME} 1)


# # Disable UART serial (unless you need it)
# pico_enable_stdio_uart(${PROJECT_NAME} 0)


# # Generate UF2, BIN, HEX files
# pico_add_extra_outputs(${PROJECT_NAME})

cmake_minimum_required(VERSION 3.13)


# Set Pico SDK path
set(PICO_SDK_PATH "/home/vboxuser/pico/pico-sdk")


# Include Pico SDK
include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)


# Project definition
project(my_first_vscode_pico LANGUAGES C CXX ASM)


# Initialize SDK
pico_sdk_init()


# Add executable
add_executable(${PROJECT_NAME}
    src/main.cpp
)


# Set C/C++ standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)


# Add compile definitions for TinyUSB
target_compile_definitions(${PROJECT_NAME} PRIVATE
    # TinyUSB configuration
    PICO_TINYUSB_HOST=0
    PICO_TINYUSB_DEVICE=1
    CFG_TUSB_DEBUG=0
    CFG_TUSB_MCU=OPT_MCU_RP2040
    CFG_TUSB_OS=OPT_OS_PICO
    
    # Enable USB features
    LIB_PICO_STDIO_USB=1
    LIB_PICO_STDIO_UART=0
    PICO_DEFAULT_UART=0
    PICO_DEFAULT_UART_TX_PIN=0
    PICO_DEFAULT_UART_RX_PIN=1
)


# Add include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${PICO_SDK_PATH}/src/common/pico_base/include
    ${PICO_SDK_PATH}/src/common/pico_stdlib/include
    ${PICO_SDK_PATH}/src/rp2_common/pico_stdio/include
    ${PICO_SDK_PATH}/src/rp2_common/hardware_gpio/include
    ${PICO_SDK_PATH}/lib/tinyusb/src
    ${PICO_SDK_PATH}/lib/tinyusb/hw
    ${PICO_SDK_PATH}/src/rp2_common/pico_stdio_usb/include
)


# Link required libraries
target_link_libraries(${PROJECT_NAME}
    # Core libraries
    pico_stdlib
    hardware_gpio
    
    # USB libraries
    pico_stdio_usb
    pico_tinyusb_device
    hardware_pio
    hardware_dma
    
    # HID support
    usb_device
    usb_common
)


# Enable USB stdio (for printf)
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)


# Generate additional output files
pico_add_extra_outputs(${PROJECT_NAME})