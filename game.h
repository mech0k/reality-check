#include "switches.h"
#include "level.h"

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h> 

#define LED_ON      PORTB |=  _BV(PINB7)
#define LED_OFF     PORTB &= ~_BV(PINB7) 
#define LED_TOGGLE  PINB  |=  _BV(PINB7)


typedef enum {Up,Down,Left,Right} direction;

void redraw_p();
void spawn();
void generate_g();
void move_p(direction m);
uint8_t check_col(uint8_t x, uint8_t y);
void restart_lvl();
void check_lvl();
void display_title();
