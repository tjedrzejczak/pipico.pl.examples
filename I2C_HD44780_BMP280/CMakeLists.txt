cmake_minimum_required(VERSION 3.13)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(I2C_HD44780_BMP280 C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

include_directories(../picolib/I2C)
include_directories(../picolib/HD44780_I2C)
include_directories(../picolib/BMP280_I2C)

add_executable(${PROJECT_NAME}
    main.cpp
    ../picolib/I2C/I2C.cpp
    ../picolib/HD44780_I2C/HD44780_I2C.cpp
    ../picolib/BMP280_I2C/BMP280_I2C.cpp
)

pico_add_extra_outputs(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} pico_stdlib hardware_i2c)

pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)
