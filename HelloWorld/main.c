#include <stdio.h>
#include "pico/stdlib.h"

void blinkLed(uint pin, uint32_t ms) {
    printf("Blinking led on pin %d - %d ms\r\n", pin, ms);

    gpio_put(pin, true);
    sleep_ms(ms);
    gpio_put(pin, false);
}

int main() {
    const uint led1_pin = 25; // onboard led
    const uint led2_pin = 22; // external led

    gpio_init(led1_pin);
    gpio_set_dir(led1_pin, GPIO_OUT);
    gpio_init(led2_pin);
    gpio_set_dir(led2_pin, GPIO_OUT);

    stdio_init_all();

    while (true) {
        printf("new loop\r\n");

        blinkLed(led1_pin, 500);

        for(uint i = 0; i < 3; i++) {
            blinkLed(led2_pin, 300);
            sleep_ms(200);
        }

        blinkLed(led1_pin, 500);
        blinkLed(led2_pin, 500);
    }
}