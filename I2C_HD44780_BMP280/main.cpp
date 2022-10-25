#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "I2C.hpp"
#include "HD44780_I2C.hpp"
#include "BMP280_I2C.hpp"

int main()
{
    stdio_init_all();

    printf("start ");

    I2CPort port0 = I2CPort(i2c_default, 100 * 1000, PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN);
    port0.Init();

    BMP280Device bmp280 = BMP280Device(&port0, 0x76);
    bmp280.Init();
    sleep_ms(250);

    HD44780Device lcd = HD44780Device(&port0, 0x27);
    lcd.Init();
    sleep_ms(250);

    while (1)
    {
        BMP280_temperature_pressure_t result = bmp280.Read();

        float pres = result.pressure / 100.0f;
        float temp = result.temperature / 100.0f;
        printf("Pressure = %.3f hPa\n", pres);
        printf("Tempersture = %.2f C\n", temp);

        lcd.Clear();
        lcd.PrintTextFormat(0, 0, "%.0f hPa  %.0f C", pres, temp);

        sleep_ms(1500);
    }
}