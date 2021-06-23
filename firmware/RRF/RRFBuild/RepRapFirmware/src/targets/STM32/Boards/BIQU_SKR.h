#ifndef BIQU_SKR_H
#define BIQU_SKR_H

#include "../Pins_STM32.h"

// List of assignable pins and their mapping from names to MPU ports. This is indexed by logical pin number.
// The names must match user input that has been converted to lowercase and had _ and - characters stripped out.
// Aliases are separate by the , character.
// If a pin name is prefixed by ! then this means the pin is hardware inverted. The same pin may have names for both the inverted and non-inverted cases,
// for example the inverted heater pins on the expansion connector are available as non-inverted servo pins on a DFueX.

constexpr PinEntry PinTable_BIQU_SKR_PRO_v1_1[] =
{
    //Thermistors
    {PF_3, "e0temp,t0"},
    {PF_4, "e1temp,t1"},
    {PF_5, "e2temp,t2"},
    {PF_6, "bedtemp,t3"},

    //Endstops
    {PB_10, "xstop,x-stop"},
    {PE_12, "ystop,y-stop"},
    {PG_8, "zstop,z-stop"},
    {PE_15, "e0stop,e0det"},
    {PE_10, "e1stop,e1det"},
    {PG_5, "e2stop,e2det"},
	{PA_2, "probe"},
	
    //Heaters and Fans (Big and Small Mosfets}
    {PD_12,  "bed,hbed" },
    {PB_1,  "e0heat,he0" },
    {PD_14,  "e1heat,he1" },
    {PB_0,  "e2heat,he2" },
    {PC_8,  "fan0,fan" },
    {PE_5,  "fan1" },
    {PE_6,  "fan2" },

    //Servos
    {PA_1,  "servo0" },
	
    //EXP1
    {PG_4, "PG4"},
    {PA_8, "PA8"},
    {PD_11, "PD11"},
    {PD_10, "PD10"},
    {PG_2, "PG2"},
    {PG_3, "PG3"},
    {PG_6, "PG6"},
    {PG_7, "PG7"},

    //EXP2
    {PB_14, "PB14"},
    {PB_13, "PB13"},
    {PG_10, "PG10"},
    {PB_12, "PB12"},
    {PF_11, "PF11"},
    {PB_15, "PB15"},
    {PF_12, "PF12"},
    {PF_13, "PF13"},

	//Extension 1
	{PC_9, "PC9"},
	{PF_9, "PF9"},
	{PC_4, "PC4"},
	{PG_11, "PG11"},
	{PG_14, "PG14"},
	{PC_1, "PC1"},
	{PF_8, "PF8"},
	{PF_10, "PF10"},
	{PC_5, "PC5"},
	{PG_13, "PG13"},
	{PD_3, "PD3"},
	{PF_7, "PF7"},

	//Extension 2
	{PD_0, "PD0"},
	{PD_2, "PD2"},
	{PD_0, "PD5"},
	{PE_0, "PE0"},
	{PE_2, "PE2"},
	{PE_4, "PE4"},

	//Wifi
	{PG_0, "wifi1,PG0"},
	{PG_1, "wifi2,PG1"},
	{PC_7, "wifi3,PC7"},
	{PC_6, "wifi4,PC6"},
	{PF_14, "wifi5,PF14"},
	{PF_15, "wifi6,PF15"},
	
	//SPI
	{PC_10, "PC10"},
	{PC_11, "PC11"},
	{PA_15, "X-CS,PA15"},
	{PC_12, "PC12"},
	{PB_9, "Z-CS,PB9"},
	{PB_8, "Y-CS,PB8"},
	{PB_3, "E0-CS,PB3"},
	{PG_15, "E1-CS,PG15"},
	{PG_12, "E2-CS,PG12"},
	
	//I2C
	{PB_7, "PB7"},
	{PB_6, "PB6"},
	
	//UART
	{PD_9, "PD9"},
	{PD_8, "PD8"},

};

constexpr BoardDefaults biquskr_pro_1_1_Defaults = {
    {0x768a39d6, 0x50da391},                 	// Signatures
    SD_SPI1_A,                                  // SD Card access
    {   //CLK, MISO, MOSI
        {PA_5, PA_6, PB_5},                     //SPI0
        {PB_13, PB_14, PB_15},                  //SPI1
        {PC_10, PC_11, PC_12},                  //SPI2
        {NoPin, NoPin, NoPin},                  //SPI3
        {NoPin, NoPin, NoPin},                  //SPI4
        {NoPin, NoPin, NoPin},                  //SPI5
    },
	6,											// Number of drivers
    {PF_2, PD_7,  PC_0, PC_3,  PA_3, PF_0},   	//enablePins
    {PE_9, PE_11, PE_13, PE_14,  PD_15, PD_13},	//stepPins
    {PF_1, PE_8, PC_2, PA_0,  PE_7, PG_9},    	//dirPins
#if HAS_SMART_DRIVERS
    {PC_13, PE_3, PE_1, PD_4, PD_1, PD_6},      //uartPins
    6,                                      	// Smart drivers
#endif
    0,                                       	//digiPot Factor
#if HAS_VOLTAGE_MONITOR
    NoPin,
#endif
    NoPin,
};


constexpr PinEntry PinTable_BIQU_GTR_v1_0[] =
{
    //Thermistors
    {PC_1, "e0temp,t0"},
    {PC_2, "e1temp,t1"},
    {PC_3, "e2temp,t2"},
    {PC_0, "bedtemp,t3"},
	{PA_3, "e3temp,TempM1"},
	{PF_9, "e4temp,TempM2"},
	{PF_10, "e5temp,TempM3"},
	{PF_7, "e6temp,TempM4"},
	{PF_5, "e7temp,TempM5"},

    //Endstops
    {PF_2, "xstop,x-stop"},
    {PC_13, "ystop,y-stop"},
    {PE_0, "zstop,z-stop"},
    {PG_14, "e0stop,e0det"},
    {PG_9, "e1stop,e1det"},
    {PD_3, "e2stop,e2det"},
	{PI_4, "e3stop,M1Stop"},
	{PF_4, "e4stop,M2Stop"},
	{PF_6, "e5stop,M3Stop"},
	{PI_7, "e6stop,M4Stop"},
	{PF_12, "e7stop,M5Stop"},
	{PH_11, "probe"},
	{PI_11, "EI1,PI11"},
	{PH_6, "EI2,PH6"},
	
    //Heaters and Fans (Big and Small Mosfets}
    {PA_2,  "bed,hbed" },
    {PB_1,  "e0heat,heat0" },
    {PA_1,  "e1heat,heat1" },
    {PB_0,  "e2heat,heat2" },
	{PD_15,  "e3heat,heatM1" },
	{PD_13,  "e4heat,heatM2" },
	{PD_12,  "e5heat,heatM3" },
	{PE_13,  "e6heat,heatM4" },
	{PI_6,  "e7heat,heatM5" },
    {PE_5,  "fan0" },
    {PE_6,  "fan1" },
    {PC_8,  "fan2" },
	{PI_5,  "fanM1" },
	{PE_9,  "fanM2" },
	{PE_11,  "fanM3" },
	{PC_9,  "fanM4" },
	{PE_14,  "fanM5" },

    //Servos
    {PB_11,  "servo0" },
	
    //EXP1
    {PC_11, "PC11"},
    {PA_15, "PA15"},
    {PC_10, "PC10"},
    {PA_8, "PA8"},
    {PG_8, "PG8"},
    {PG_7, "PG7"},
    {PG_6, "PG6"},
    {PG_5, "PG5"},

    //EXP2
    {PB_14, "PB14"},
    {PB_13, "PB13"},
    {PD_10, "PD10"},
    {PB_12, "PB12"},
    {PH_10, "PH10"},
    {PB_15, "PB15"},
    {PB_10, "PB10"},
	
	//Extension-0
	{PH_13, "PH13"},
	{PI_9, "PI9"},
	
	//Extension-1
	{PI_10, "PI10"},
	{PI_8, "PI8"},
	
	//Extension-2
	{PH_8, "PH8"},
	{PH_7, "PH7"},
	
	//Neopixel
	{PF_13, "Neopixel,PF13"},

	//Wifi
	{PF_11, "wifi1,PF11"},
	{PC_7, "wifi3,PC7"},
	{PC_6, "wifi4,PC6"},
	{PC_5, "wifi5,PC5"},
	
	//Raspberry Pi
	{PA_10, "PA10"},
	{PA_9, "PA9"},
	
	//SPI
	{PC_14, "X-CS,PC14"},
	{PE_1, "Y-CS,PE1"},
	{PB_5, "Z-CS,PB5"},
	{PG_10, "E0-CS,PG10"},
	{PD_4, "E1-CS,PD4"},
	{PC_12, "E2-CS,PC12"},
	{PB_6, "MISO,PB6"},
	{PG_15, "MOSI,PG15"},
	{PB_3, "SCK,PB3"},
	
	//Extra M5
	{PI_2, "KMOSI,PI2"},
	{PI_1, "KSCK,PI1"},
	{PH_2, "KCS,PH2"},
	{PF_13, "RGB_LED,PF13"},
};

constexpr BoardDefaults biqu_gtr_1_0_Defaults = {
    {0x94a2cc03},                 				// Signatures
    SD_SPI1_B,                                  // SD Card access
    {   //CLK, MISO, MOSI
        {PA_5, PA_6, PA_7},                     //SPI0
        {PB_13, PB_14, PB_15},                  //SPI1
        {NoPin, NoPin, NoPin},                  //SPI2
        {NoPin, NoPin, NoPin},                  //SPI3
        {NoPin, NoPin, NoPin},                  //SPI4
        {NoPin, NoPin, NoPin},                  //SPI5
    },
	6+5,										// Number of drivers GTR + M5
	{PF_1, PE_4,  PB_9, PG_13,  PD_7, PD_2,PF_8,PG_2,PF_4,PE_8,PI_0},    //enablePins including M5
	{PC_15, PE_3, PB_8, PG_12,  PD_6, PD_1,PF_3,PD_14,PE_12,PG_0,PH_12},    //stepPins Including M5
	{PF_0, PE_2, PB_7, PG_11,  PD_5, PD_0,PG_3,PD_11,PE_10,PG_1,PH_15}, //dirPins Including M5
#if HAS_SMART_DRIVERS
	{PC_14, PE_1, PB_5, PG_10, PD_4, PC_12,PG_4,PE_15,PE_7,PF_15,PH_14},  //uartpins including M5
    6,                                      // Smart drivers or 11 with M5
#endif
    0,                                       //digiPot Factor
#if HAS_VOLTAGE_MONITOR
    NoPin,
#endif
    NoPin,
};

constexpr PinEntry PinTable_BTT_RRF_E3_v1_1[] =
{
    //Thermistors
    {PA_0, "e0temp,th0"},
    {PA_1, "bedtemp,tb"},
    {PA_2, "e1temp,th1"},
    {PA_3, "PT100,th2"},

    //Endstops
    {PC_0, "xstop,x-stop"},
    {PC_1, "ystop,y-stop"},
    {PC_2, "zstop,z-stop"},
    {PC_3, "e0stop,e0det"},
    {PB_10, "e1stop"},
    {PB_11, "x2stop"},
    {PE_3, "IO"},

    //Servos
    {PB_0,  "servo0" },

    //Probe
    {PC_5, "probe"},

    //Heaters and Fans (Big and Small Mosfets}
    {PB_4,  "bed,hbed" },
    {PB_3,  "e0heat,heat0" },
    {PE_4,  "e1heat" },
    {PB_5,  "fan0,fan" },
    {PB_6,  "fan1" },
    {PE_5,  "fan2" },
    {PE_6,  "fan3" },

    //EXP1
    {PB_1, "LCDCS"},
    {PB_2, "LCDENCB"},
    {PE_7, "LCDENCB"},
    {PE_8, "LCDBEEP"},
    {PE_9,"LCDBTN"},
    {PE_10, "LCDD4"},
    {PE_11,"LCDEN"},

	//Neopixel
    {PB_7, "Neopixel,PB7"},

    //TFT
    {PA_9, "TX1,tft-tx"},
    {PA_10, "RX1,tft-rx"},

    //WIFI UART
    {PD_8, "PD8"},
    {PD_9, "PD9"},
	
    //UART
    {PB_8, "SDA1,PB8"},
    {PB_9, "SCL1,PB9"},	

    //WIFI
    {PD_13, "PD13"},//RST
    {PD_12, "PD12"},//EN
    {PD_11, "PD11"},//IO0
    {PD_10, "PD10"},//IO2
    {PA_4, "PA4"}, //RST
    {PA_5, "PA5"}, //EN
    {PA_6, "PA6"}, //IO0
    {PA_7, "PA7"}, //IO4
    {PB_12, "PB12"},//CS
    {PB_13, "PB13"},//CLK
    {PB_14, "PB14"},//MISO
    {PB_15, "PB15"},//MOSI
	
    //PSON
    {PE_1, "PSON,PE1"},
	
    //PWRDET
    {PE_0, "PWRDET,PE0"},
	
    //Status LED
    {PE_2, "LED,PE2"},
	
    //J7
    //{PE_3, "PE3"},
    //{PE_4, "PE4"},
    //{PE_5, "PE5"},
    //{PE_6, "PE6"},
    //{PC_13, "PC13"},
    //{PC_14, "PC14"},
    //{PC_15, "PC15"},
    //{PA_8, "PA8"},
    //{PA_2, "PA2"},
    //{PA_3, "PA3"},
    //{PE_12, "PE12"},
    //{PE_13, "PE13"},
    //{PE_14, "PE14"},
    //{PE_15, "PE15"},
    //{PB_10, "PB10"},
    //{PB_11, "PB11"},
};

constexpr BoardDefaults btt_rrf_e3_1_1_Defaults = {
    {0x94a2cc03},                 				// Signatures
    SD_SPI1_B,                                  // SD Card access
    {   //CLK, MISO, MOSI
        {PA_5, PA_6, PA_7},                     //SPI0
        {PB_13, PB_14, PB_15},                  //SPI1
        {NoPin, NoPin, NoPin},                  //SPI2
        {NoPin, NoPin, NoPin},                  //SPI3
        {NoPin, NoPin, NoPin},                  //SPI4
        {NoPin, NoPin, NoPin},                  //SPI5
    },
    6,							// Number of drivers
    {PD_7, PD_3, PD_14, PD_10, PC_13, PE_15}, // enablePins
    {PD_5, PD_0, PC_6, PD_12, PC_15, PE_13},  // stepPins
    {PD_4, PA_15, PC_7, PD_13, PA_8, PE_12},	// dirPins
#if TMC_SOFT_UART
    {PD_6, PD_1, PD_15, PD_11, PC_14, PE_14},	// uartpins
    4,							// Smart drivers
#endif
    0,							// digiPot Factor
#if HAS_VOLTAGE_MONITOR
    NoPin,
#endif
    NoPin,
};

constexpr PinEntry PinTable_BTT_SKR_2[] =
{
    //Thermistors
    {PA_1, "bedtemp,tb"},
    {PA_2, "e0temp,th0"},
    {PA_3, "e1temp,th1"},

    //Endstops
    {PC_1, "xstop,x-stop"},
    {PC_3, "ystop,y-stop"},
    {PC_0, "zstop,z-stop"},
    {PC_2, "e0stop,e0det"},
    {PA_0, "e1stop,e1det"},

    //Servos
    {PE_5,  "servo0" },

    //Probe
    {PE_4, "probe"},

    //Heaters and Fans (Big and Small Mosfets}
    {PD_7,  "bed,hbed" },
    {PB_3,  "e0heat,heat0" },
    {PB_4,  "e1heat,heat1" },
    {PB_7,  "fan0,fan" },
    {PB_6,  "fan1" },
    {PB_5,  "fan2" },

    //EXP1
    {PE_9, "LCDCS"},
    {PB_2, "LCDENCA"},
    {PE_7, "LCDENCB"},
    {PC_5, "LCDBEEP"},
    {PB_0, "LCDBTN"},
    {PE_10, "LCDD4"},
    {PB_1, "LCDEN"},

    //Neopixel
    {PE_6, "Neopixel,PE6"},

    //TFT
    {PA_9, "TX1,tft-tx"},
    {PA_10, "RX1,tft-rx"},

    //WIFI UART
    {PD_8, "PD8"},
    {PD_9, "PD9"},

    //SPI
    {PE_0, "X-CS,PE0"},
    {PD_3, "Y-CS,PD3"},
    {PD_0, "Z-CS,PD0"},
    {PC_6, "E0-CS,PC6"},
    {PD_12, "E1-CS,PD12"},
    {PA_14, "MISO,PA14"},
    {PE_14, "MOSI,PE14"},
    {PE_15, "SCK,PE15"},

    //I2C
    {PB_8, "SCL1,PB8"},
    {PB_9, "SDA1,PB9"},

    //WIFI
    {PC_14, "PC14"}, //RST
    {PB_10, "PB10"}, //IO0
    {PB_11, "PB11"}, //IO4
    {PB_12, "PB12"}, //CS
    {PB_13, "PB13"}, //CLK
    {PB_14, "PB14"}, //MISO
    {PB_15, "PB15"}, //MOSI

    //PSON
    {PE_8, "PSON,PE8"},

    //PWRDET
    {PC_15, "PWRDET,PC15"},

    //Status LED
    {PA_13, "LED,PA13"},

    //Safe power
    {PC_13, "SP,PC13"},
};

constexpr BoardDefaults btt_skr_2_Defaults = {
    {0xb75b00a7},                 				// Signatures
    SD_SDIO,                                  // SD Card access
    {   //CLK, MISO, MOSI
        {PA_5, PA_6, PA_7},                     //SPI0
        {PB_13, PB_14, PB_15},                  //SPI1
        {NoPin, NoPin, NoPin},                  //SPI2
        {NoPin, NoPin, NoPin},                  //SPI3
        {NoPin, NoPin, NoPin},                  //SPI4
        {NoPin, NoPin, NoPin},                  //SPI5
    },
    5,							// Number of drivers
    {PE_3, PD_6, PD_1, PC_7, PD_13}, // enablePins
    {PE_2, PD_5, PA_15, PD_15, PD_11},  // stepPins
    {PE_1, PD_4, PA_8, PD_14, PD_10},	// dirPins
#if TMC_SOFT_UART
    {PE_0, PD_3, PD_0, PC_6, PD_12},	// uartpins
    5,							// Smart drivers
#endif
    0,							// digiPot Factor
#if HAS_VOLTAGE_MONITOR
    NoPin,
#endif
    PC_13,
};

#endif