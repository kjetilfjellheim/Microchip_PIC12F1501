
#define _XTAL_FREQ 16000000

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h" 

void main(void)
{
    /**
     * Configure oscillator.
     */
    ConfigureOscillator();

    /**
     * Initialize.
     */
    InitApp();

    /**
     * Main application logic.
     */
    while(1)
    {
        /**
         * Start temperature measurement.
         */
        ADCON0bits.ADGO = 1;
        /**
         * Wait until measurement is completed and ADGO is 0.
         */
        while (ADCON0bits.ADGO);
        /**
         * Read measurement.
         */
        int measuredVal = getMeasurement();
        int temperature = calculateTemperature(measuredVal); 
        /**
         * Wait one second for the next measurement.
         */
        __delay_ms(1000);
    }

}

