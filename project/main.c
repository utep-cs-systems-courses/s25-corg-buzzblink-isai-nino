#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "switches.h"
#include "led.h"

int main()
{  
  configureClocks();
  enableWDTInterrupts();

  led_init();
  buzzer_init();
  switch_init();

  P1OUT |= LED_GREEN;
  
  or_sr(0x18);             // CPU off, GIE on
}
