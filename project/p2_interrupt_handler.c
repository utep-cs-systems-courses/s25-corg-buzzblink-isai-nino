#include <msp430.h>
#include "switches.h"
#include "led.h"

void __interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES) {
    P2IFG &= ~SWITCHES;
    switch_interrupt_handler();
  }
}

int blink_limit = 5;  // Duty cycle = 1/blink_limit
int blink_count = 0;  
int second_count = 0;

void __interrupt_vec(WDT_VECTOR) WDT()
{
  // Handle blinking
  blink_count++;
  if (blink_count >= blink_limit) { /* once each sec... */
    blink_count = 0;/* reset count */
    P1OUT |= LED_RED;
    P1OUT |= LED_GREEN;
  } else {
    P1OUT &= ~LED_RED;
    P1OUT &= ~LED_GREEN;
  }
  
  // Measure a second
  second_count++;
  if (second_count >= 250) {
    second_count = 0;
    // blink_limit++;
    if (blink_limit > 8)
      blink_limit = 9;
  }
}
