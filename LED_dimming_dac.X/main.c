
#if defined(__XC)
#include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
#include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */

#define _XTAL_FREQ 4000000

void main(void) {
    ConfigureOscillator();

    InitApp();

    while (1) {
        for (int i=0;i<32;i++) {
            DACCON1bits.DACR = i;
            __delay_ms(20);
        } 
        
    }

}

