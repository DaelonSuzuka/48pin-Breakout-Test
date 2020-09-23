#include "config.h"
#include "os/system_clock.h"
#include "pins.h"
#include "system.h"
#include <stdbool.h>

/* ************************************************************************** */

//
#define LED_ONE_COOLDOWN 200

bool attempt_led_one_blink(void) {
    static system_time_t lastAttempt = 0;
    if (time_since(lastAttempt) < LED_ONE_COOLDOWN) {
        return false;
    }
    lastAttempt = get_current_time();

    static bool state = false;

    if (state) {
        set_LED_ONE_PIN(0);
        state = false;
    } else {
        set_LED_ONE_PIN(1);
        state = true;
    }

    return true;
}

/* -------------------------------------------------------------------------- */

//
#define LED_TWO_COOLDOWN 1000

bool attempt_led_two_blink(void) {
    static system_time_t lastAttempt = 0;
    if (time_since(lastAttempt) < LED_TWO_COOLDOWN) {
        return false;
    }
    lastAttempt = get_current_time();

    static bool state = false;

    if (state) {
        set_LED_TWO_PIN(0);
        state = false;
    } else {
        set_LED_TWO_PIN(1);
        state = true;
    }

    return true;
}
/* ************************************************************************** */

void main(void) {
    startup();

    while (1) {
        attempt_led_one_blink();
        attempt_led_two_blink();
    }
}