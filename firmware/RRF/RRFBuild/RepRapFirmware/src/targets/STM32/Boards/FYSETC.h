#ifndef FYSETC_H
#define FYSETC_H

#include "../Pins_STM32.h"

// List of assignable pins and their mapping from names to MPU ports. This is indexed by logical pin number.
// The names must match user input that has been converted to lowercase and had _ and - characters stripped out.
// Aliases are separate by the , character.
// If a pin name is prefixed by ! then this means the pin is hardware inverted. The same pin may have names for both the inverted and non-inverted cases,
// for example the inverted heater pins on the expansion connector are available as non-inverted servo pins on a DFueX.

constexpr PinEntry PinTable_FYSETC_SPIDER[] =
{
    //Thermistors
    {PC_0, "e0temp,t0"},
    {PC_1, "e1temp,t1"},
    {PC_2, "e2temp,t2"},
    {PC_3, "bedtemp,t3"},

    //Endstops
    {PB_14,   "xstop,x-stop"},
    {PB_13,   "ystop,y-stop"},
    {PA_0,   "zstop,z-stop"},
    {PA_1,   "e0stop,e0det"},
    {PA_2,   "probe"},
	
    //Heaters and Fans (Big and Small Mosfets}
    {PB_4,    "bed,hbed" },
    {PB_15,    "e0heat,he0" },
    {PC_8,    "e1heat,he1" },
    {PB_3,    "e2heat,he2" },
    {PB_0,    "fan0,fan" },
    {PB_1,    "fan1" },
    {PB_2,    "fan2" },

    //Servos
    {PA_3,    "servo0" },
	
    //EXP1
//    {PD_1,   "PD1"},
//    {PD_0,   "PD0"},
//    {PC_12,   "PC12"},
//    {PC_10,   "PC10"},
//    {PD_2,   "PD2"},
//    {PC_11,   "PC11"},
//    {PA_8,   "PA8"},
//    {PC_7,   "PC9"},

    //EXP2
//    {PA_6,   "PA6"},  // MISO
//    {PA_5,   "PA5"},  // SCK
//    {PC_6,   "PC6"},  // ENC_A
//    {PA_4,   "PA4"},  // CS
//    {PC_7,   "PC7"},  // ENC_B
//    {PA_7,   "PA7"},  // MOSI
//    {PB_10,  "PB10"},// SD_DET
	
  	//SPI
//    {PE_12,   "PE12"}, // SCK4
//    {PE_13,   "PE13"}, // MISO4
//    {PE_14,   "PE14"}, // MOSI4
//    {PE_7,    "X-CS,PE7"},
//    {PD_10,   "Z-CS,PD10"},
//    {PE_15,   "Y-CS,PE15"},
//    {PD_7,    "E0-CS,PD7"},
//    {PC_14,   "E1-CS,PC14"},
//    {PC_15,   "E2-CS,PC15"},
//    {PA_15,   "E3-CS,PA15"},
//    {PD_11,   "E4-CS,PD11"},
  	
  	//I2C
//    {PB_9,   "PB9"},  // SDA
//    {PB_8,   "PB8"},  // SCL
  	
  	//UART
//    {PA_9,   "PA9"},  // TX1
//    {PA_10,  "PA8"}, // RX1

  	// NEOPIXEL
//    {PD_3,   "PD3"},

    // RGB
//    {PB_6,   "PB6"},
//    {PB_5,   "PB5"},
//    {PB_7,   "PB7"},

};

constexpr BoardDefaults fysetc_spider_Defaults = {
    {0x8479e19e, 0x5f0d840c},                   // Signature
    SD_SPI1_B,                                  // SD Card access
    {   //CLK, MISO, MOSI
        {PA_5, PA_6, PA_7},                     //SPI0
        {NoPin, NoPin, NoPin},                  //SPI1
        {PC_10, PC_11, PC_12},                  //SPI2
        {PE_12, PE_13, PE_14},                  //SPI3
        {NoPin, NoPin, NoPin},                  //SPI4
        {NoPin, NoPin, NoPin},                  //SPI5
    },
	8,											// Number of drivers
    {PE_9,  PD_9,  PD_15, PD_4, PE_5,  PE_3,  PE_8,  PC_5},   	//enablePins
    {PE_11, PD_8,  PD_14, PD_5, PE_6,  PE_2,  PD_12, PE_1},	    //stepPins
    {PE_10, PB_12, PD_13, PD_6, PC_13, PE_4,  PC_4,  PE_0},    	//dirPins
#if HAS_SMART_DRIVERS
    {PE_7,  PE_15, PD_10, PD_7, PC_14, PC_15, PA_15, PD_11},    //uartPins
    8,                                      	// Smart drivers
#endif
    0,                                       	//digiPot Factor
#if HAS_VOLTAGE_MONITOR
    NoPin,
#endif
};

#endif