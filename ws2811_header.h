/* 
 * File:   ws2811_header.h
 * Author: Gamini
 *
 * Created on December 5, 2020, 8:25 AM
 */

#ifndef WS2811_HEADER_H
#define	WS2811_HEADER_H

#ifdef	__cplusplus
extern "C" {
#endif

/* WS2811/WS2812 GRB NeoPixel/RGB LED Controller Interfacing*/

/* 
  * Notes:-
  * Ver 1 :-
  *         This code gets buggy on several times and finally at the moment i type this the firmware works on Protues simulation.
  *         The initial setting are base on Datasheet "https://cdn-shop.adafruit.com/datasheets/WS2811.pdf".
  *         The processor set to external HS oscillator configuration at 20MHz.
  *         Single LED represents 24bit data. Therefore n amount of LEDs take 24*n bits.
  *         Example, To address 3 LEDs,I have to use 3*24 bits and use reset function.
  *         To end the transmission.Just put reset function at the END.
  * 
  *         Finally in this version.Both Proteus Simulation and real Hardware Implementations are tested and works perfect
  *         To mention that original Datasheet "https://cdn-shop.adafruit.com/datasheets/WS2811.pdf" mention that the data composition of 24-bits should GRB.and it works on Proteus Simulation.
  *         But in the real Hardware simulation, The GRB composition isn't working.Therefore when interfacing real Hardware, use RGB composition.
  * 
  * 
*/
    
/*
 *  24-bit composition for Proteus Simulation (According to the Datasheet).
 * 
    //---------------------- Green.
    ws2811_1wire_low();
    ws2811_1wire_low();
    ws2811_1wire_low();
    ws2811_1wire_low();
    ws2811_1wire_low();
    ws2811_1wire_low();
    ws2811_1wire_low();
    ws2811_1wire_low();
    //---------------------- Red.
    ws2811_1wire_high();
    ws2811_1wire_high();
    ws2811_1wire_high();
    ws2811_1wire_high();
    ws2811_1wire_high();
    ws2811_1wire_high();
    ws2811_1wire_high();
    ws2811_1wire_high();
    //---------------------- Blue.
    ws2811_1wire_low();
    ws2811_1wire_low();
    ws2811_1wire_low();
    ws2811_1wire_low();
    ws2811_1wire_low();
    ws2811_1wire_low();
    ws2811_1wire_low();
    ws2811_1wire_low(); 
    //----------------------- Reset :- Reset will separate number of LEDs.24-bits represent a single LED.
    ws2811_1wire_reset();
 * 
 * 24-bit composition for real Hardware.
 * 
 * //---------------------- Red.
    ws2811_1wire_low();
    ws2811_1wire_low();
    ws2811_1wire_low();
    ws2811_1wire_low();
    ws2811_1wire_low();
    ws2811_1wire_low();
    ws2811_1wire_low();
    ws2811_1wire_low();
    //---------------------- Green.
    ws2811_1wire_high();
    ws2811_1wire_high();
    ws2811_1wire_high();
    ws2811_1wire_high();
    ws2811_1wire_high();
    ws2811_1wire_high();
    ws2811_1wire_high();
    ws2811_1wire_high();
    //---------------------- Blue.
    ws2811_1wire_low();
    ws2811_1wire_low();
    ws2811_1wire_low();
    ws2811_1wire_low();
    ws2811_1wire_low();
    ws2811_1wire_low();
    ws2811_1wire_low();
    ws2811_1wire_low(); 
    //----------------------- Reset :- Reset will separate number of LEDs.24-bits represent a single LED.
    ws2811_1wire_reset();
 */
#include <stdio.h>
#include <stdlib.h>
#include "pic18f4550.h"
// TRIS and PORTB Pin 0 assigned for 1-wire transmission.
   //TRISBbits.TRISB0 = 0;// Clear TRISB.F0.
   //PORTBbits.RB0 = 0;// Clear PORTB.F0.
/*----------------------------- Custom Functions --------------------------------*/
//--------------------------------------------------------------- One Wire High.
void ws2811_1wire_high()
  {
    PORTBbits.RB0 = 1;// T1H
    __delay_us(12/10);
    PORTBbits.RB0 = 0;// T1L
    __delay_us(5/10);
  }
//---------------------------------------------------------------- One Wire Low.
void ws2811_1wire_low()
  {
    PORTBbits.RB0 = 1;// T0H
    __delay_us(5/10);
    PORTBbits.RB0 = 0;// T0L
    __delay_us(2/10);
  }
//-------------------------------------------------------------- One Wire Reset.
void ws2811_1wire_reset()
  {
    PORTBbits.RB0 = 0;
    __delay_us(50);
  }
#ifdef	__cplusplus
}
#endif

#endif	/* WS2811_HEADER_H */

