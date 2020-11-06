#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

void setup(void);

void setup(void) {
    rcc_periph_clock_enable(RCC_GPIOC);

    gpio_mode_setup(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO13);
}

int main(void) {
    rcc_clock_setup_pll(&rcc_hse_25mhz_3v3[RCC_CLOCK_3V3_84MHZ]);
    rcc_periph_clock_enable(RCC_GPIOC);

    gpio_mode_setup(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO13);

    setup();

    while (1) {
        gpio_toggle(GPIOC, GPIO13);
        for (int i = 0;i < 10000000; i++) {
            __asm__("nop");
        }
    }
    
    return 0;
}
