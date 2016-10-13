
#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>

#include "user.h"

void InitApp(void)
{
    /**
     * Set A0 as output.
     */
    TRISAbits.TRISA0 = 0;
    /**
     * Set A2 as output.
     */    
    TRISAbits.TRISA2 = 0;   
    /**
     * Enable DAC
     */
    DACCON0bits.DACEN = 1;
    /**
     * Enable DAC on A0
     */
    DACCON0bits.DACOE1 = 1;
    /**
     * Enable DAC on A2
     */
    DACCON0bits.DACOE2 = 0;
    /**
     * Set external as reference to DAC.
     */
    DACCON0bits.DACPSS = 1;        
}

