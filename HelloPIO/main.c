#include <stdio.h>
#include "pico/stdlib.h"
#include "hello.pio.h"

int main()
{
    const uint led1_pin = 25;
    const float freq = 2000; // Hz

    stdio_init_all();

    PIO pio = pio0;
    uint sm = pio_claim_unused_sm(pio, true);
    uint offset = pio_add_program(pio, &hello_program);

    hello_program_init(pio, sm, offset, led1_pin, freq);

    while (true)
    {
        uint32_t data = 0x55555555; // - 0101
        pio_sm_put_blocking(pio, sm, data);
        pio_sm_put_blocking(pio, sm, data);

        data = 0x33333333; // - 0011
        pio_sm_put_blocking(pio, sm, data);
        pio_sm_put_blocking(pio, sm, data);

        data = 0xffff00f0;
        pio_sm_put_blocking(pio, sm, data);
        pio_sm_put_blocking(pio, sm, data);
    }
}