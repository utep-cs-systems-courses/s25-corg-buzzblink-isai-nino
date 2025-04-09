
#include <msp430.h>
#include "switches.h"
#include "buzzer.h"
#include "led.h"

extern blink_limit;

static char switch_update_interrupt_sense()
{
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);   // If switch up, sense down
  P2IES &= (p2val | ~SWITCHES);  // If switch down, sense up
  return p2val;
}

void switch_init()
{
  P2REN |= SWITCHES;   // Enables resistors for switches
  P2IE  |= SWITCHES;   // Enables interrupts from switches
  P2OUT |= SWITCHES;   // Pull-ups for switches
  P2DIR &= ~SWITCHES;  // Set switches' buts for input
  switch_update_interrupt_sense();
}

void switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();

  if (!(p2val & SW1)) {
    buzzer_set_period(0);
  }

  if (!(p2val & SW2)) {
    buzzer_set_period(500);
  }

  if (!(p2val & SW3)) {
    blink_limit--;
  }

  if (!(p2val & SW4)) {
    blink_limit++;
  }
}
