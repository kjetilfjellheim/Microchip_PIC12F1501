
#define _XTAL_FREQ 16000000

#define MIN_TEMPERATURE -40
#define TEMP_RANGE 125

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif


void InitApp(void)
{
    /**
     * Enable temperature sensor.
     */
    FVRCONbits.TSEN = 1;
    /**
     * Enable high range temperature sensor. 
     * Make sure voltage is above 3.6V.
     */
    FVRCONbits.TSRNG = 1;
    /**
     * Enable analog to digital.
     */
    ADCON0bits.ADON = 1;
    /**
     *  Analog to digital channel set to internal temperature indicator.
     */
    ADCON0bits.CHS = 0b11101;
    /**
     * Wait 200us as specified in datasheet.
     */
    __delay_us(200);
}

/**
 * Get measurement value as int
 * 
 * @return 
 */
unsigned int getMeasurement() 
{
    unsigned char lowBits = ADRESL;
    unsigned char highBits = ADRESH;
    int val = highBits;
    val = val << 8;
    val = val + lowBits; 
    return val;
}

int calculateTemperature(int value) 
{
    /*
     * Temperature change for each bit.
     */
    double deltaTemp = TEMP_RANGE / 65535;
    /*
     * Calculate temperature.
     */
    double temp = deltaTemp * value;
    double temperature = MIN_TEMPERATURE + temp;
    /*
     * Return temperature 
     */
    return temperature;
}