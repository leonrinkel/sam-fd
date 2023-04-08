#include "led.h"

#include <hal_gpio.h>

static uint8_t num_leds = 0;
static struct led* p_leds[MAX_LEDS];

void register_led(struct led* p_led)
{
    /* Remember LED */
    p_leds[num_leds++] = p_led;

    /* Output initial state */
    gpio_set_pin_level(
        p_led->pin,
        p_led->state ^ p_led->wiring
    );
}

void led_cycle(void)
{
    /* Iterate registered LEDs */
    for (uint8_t i = 0; i < num_leds; i++)
    {
        /* Count LED on/off cycles */
        if (p_leds[i]->state == led_is_off)
        {
            p_leds[i]->cycles_since_off++;
        }
        else if (p_leds[i]->state == led_is_on)
        {
            p_leds[i]->cycles_since_on++;
        }

        /* Turn LED off after defined cycles */
        if (
            p_leds[i]->state == led_is_on &&
            p_leds[i]->cycles_since_on >= p_leds[i]->min_on_cycles
        )
        {
            p_leds[i]->state = led_is_off;
            p_leds[i]->cycles_since_off = 0;
            gpio_set_pin_level(
                p_leds[i]->pin,
                p_leds[i]->state ^ p_leds[i]->wiring
            );
        }
    }
}

void flash_led(struct led* p_led)
{
    if (
        p_led->state == led_is_off &&
        p_led->cycles_since_off >= p_led->min_off_cycles
    )
    {
        p_led->state = led_is_on;
        p_led->cycles_since_on = 0;
        gpio_set_pin_level(
            p_led->pin,
            p_led->state ^ p_led->wiring
        );
    }
}
