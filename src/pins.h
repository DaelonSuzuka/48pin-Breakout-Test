#ifndef _PINS_H_
#define _PINS_H_

#include "peripherals/pps.h"
#include <stdbool.h>

/* ************************************************************************** */
/* [[[cog
    from codegen import fmt; import pins
    cog.outl(fmt(pins.pin_declarations()))
]]] */

// GPIO read functions
// none

// Button stuff
// none

// GPIO write functions
extern void set_LED_ONE_PIN(bool value);
extern void set_LED_TWO_PIN(bool value);

// PPS initialization macros
#define PPS_DEBUG_TX_PIN PPS_OUTPUT(F, 6)
#define PPS_DEBUG_RX_PIN PPS_INPUT(F, 7)

// ADC Channel Select macros
// none

// [[[end]]]

/* ************************************************************************** */

extern void pins_init(void);

#endif /* _PINS_H_ */