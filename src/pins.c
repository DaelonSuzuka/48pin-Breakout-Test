#include "pins.h"
#include "peripherals/pic_header.h"

/* ************************************************************************** */
/* [[[cog
    from codegen import fmt; import pins
    cog.outl(fmt(pins.pin_definitions()))
]]] */

// GPIO read functions
// none

// Button stuff
// none

// GPIO write functions
void set_LED_ONE_PIN(bool value) { LATFbits.LATF4 = value; }
void set_LED_TWO_PIN(bool value) { LATFbits.LATF5 = value; }

// [[[end]]]

/* ************************************************************************** */
/* [[[cog
    from codegen import fmt; import pins
    cog.outl(fmt(pins.pins_init()))
]]] */

void pins_init(void) {
    // USB_TX_PIN
    TRISCbits.TRISC6 = 0;

    // USB_RX_PIN
    TRISCbits.TRISC7 = 1;

    // LED_ONE_PIN
    TRISFbits.TRISF4 = 0;

    // LED_TWO_PIN
    TRISFbits.TRISF5 = 0;

    // DEBUG_TX_PIN
    TRISFbits.TRISF6 = 0;

    // DEBUG_RX_PIN
    TRISFbits.TRISF7 = 1;
}
// [[[end]]]