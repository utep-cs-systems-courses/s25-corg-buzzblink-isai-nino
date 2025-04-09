#include <msp430.h>
#include "led.h"

void led_init()
{
  P1DIR |= LEDS;  // LED bits set to output
  P1OUT &= ~LEDS;
}



