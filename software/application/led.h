#ifndef LED_H
#define LED_H

#include <stdint.h>

#define MAX_LEDS 2

/** Default initial LED state */
#define DEFAULT_LED_STATE led_is_off

/** Default minimum LED on cycles */
#define DEFAULT_LED_MIN_ON_CYCLES  50
/** Default minimum LED off cycles */
#define DEFAULT_LED_MIN_OFF_CYCLES 50

/** Enum describing how a LED is wired */
enum led_wiring
{
    led_wired_active_high = 0, /** LED is wired active high */
    led_wired_active_low  = 1, /** LED is wired active low */
};

/** Enum describing the current LED state (on/off) */
enum led_state
{
    led_is_off = 0, /** LED is currently off */
    led_is_on  = 1, /** LED is currently on */
};

/** Struct containing LED configuration and state */
struct led
{
    uint8_t pin; /** GPIO pin the LED is connected to */
    enum led_wiring wiring; /** How the LED is wired */
    enum led_state state; /** Current state of the LED */
    uint32_t min_on_cycles; /** Minimum on cycles */
    uint32_t min_off_cycles; /** Minimum off cycles */
    uint32_t cycles_since_on; /** Cycles since turned on */
    uint32_t cycles_since_off; /** Cycles since turned off */
};

/** Default LED config (excluding fields pin and wiring) */
#define DEFAULT_LED_CONFIG \
    { \
        .state = DEFAULT_LED_STATE, \
        .min_on_cycles = DEFAULT_LED_MIN_ON_CYCLES, \
        .min_off_cycles = DEFAULT_LED_MIN_OFF_CYCLES, \
        .cycles_since_on = DEFAULT_LED_MIN_OFF_CYCLES, \
        .cycles_since_off = DEFAULT_LED_MIN_OFF_CYCLES, \
    }

/** Registers LED to be handled by the driver */
void register_led(struct led* p_led);

/** Trigger cyclic LED handling */
void led_cycle(void);

/** Flash LED */
void flash_led(struct led* p_led);

#endif /* LED_H */
