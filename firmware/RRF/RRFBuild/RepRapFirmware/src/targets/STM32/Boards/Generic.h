#ifndef GENERIC_H
#define GENERIC_H

#include "../Pins_STM32.h"



constexpr PinEntry PinTable_Generic[] =
{

};

constexpr BoardDefaults Generic_Defaults = {
    {},                                         // Signatures
    SD_NONE,                                    // SD Card access
    {   //CLK, MISO, MOSI
        {NoPin, NoPin, NoPin},                  //SPI0
        {NoPin, NoPin, NoPin},                  //SPI1
        {NoPin, NoPin, NoPin},                  //SPI2
        {NoPin, NoPin, NoPin},                  //SPI3
        {NoPin, NoPin, NoPin},                  //SPI4
        {NoPin, NoPin, NoPin},                  //SPI5
    },
	0,											// Number of drivers
    {NoPin, NoPin, NoPin, NoPin, NoPin},   	    //enablePins
    {NoPin, NoPin, NoPin, NoPin, NoPin},	    //stepPins
    {NoPin, NoPin, NoPin, NoPin, NoPin},    	//dirPins
#if HAS_SMART_DRIVERS
    {NoPin, NoPin, NoPin, NoPin, NoPin},        // uart pins
    0,                                      	// Smart drivers
#endif
    0,                                       	//digiPot Factor
#if HAS_VOLTAGE_MONITOR
    NoPin,
#endif
    NoPin,
};
#endif
