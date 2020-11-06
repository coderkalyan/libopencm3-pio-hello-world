#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

int main(void) {
    // sets the clock to 84Mhz & HSE to 25Mhz (change depending on board)
    rcc_clock_setup_pll(&rcc_hse_25mhz_3v3[RCC_CLOCK_3V3_84MHZ]);

    // enable peripheral clock for GPIO port c
    rcc_periph_clock_enable(RCC_GPIOC);

    // set port c pin 13 to output
    gpio_mode_setup(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO13);

    while (1) {
        // toggles the state of pin 13
        gpio_toggle(GPIOC, GPIO13);

        // "delay" by wasting cycles
        for (int i = 0;i < 10000000; i++) {
            // this means an assembly instruction for "no operation"
            __asm__("nop");
        }
    }
    
    // we should never reach here, but return 0 anyway
    return 0;
}
