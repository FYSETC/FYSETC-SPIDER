#ifndef FLY_H
#define FLY_H

#include "../Pins_STM32.h"



constexpr PinEntry PinTable_FLY_F407ZG[] =
{
    //Thermistors
    {PA_0, "e0temp,t0"},
    {PC_1, "e1temp,t1"},
    {PC_0, "e2temp,t2"},
    {PF_10, "e3temp,t3"},
    {PF_5, "e4temp,t4"},
    {PF_4, "e5temp,t5"},
    {PF_3, "bedtemp,tb"},

    //Endstops
    {PC_3, "xmin,xstop"},
    {PC_2, "xmax,xstopmax"},
    {PF_2, "ymin,ystop"},
    {PF_1, "ymax,ystopmax"},
    {PF_0, "zmin,zstop"},
    {PC_15, "zmax,zstopmax"},
    {PC_14, "z3"},
    {PA_3, "dljc"},
	
    //Heaters and Fans (Big and Small Mosfets}
    {PE_2,  "bed,hbed" },
    {PF_7,  "e0heat,he0" },
    {PF_6,  "e1heat,he1" },
    {PE_6,  "e2heat,he2" },
    {PE_5,  "e3heat,he3" },
    {PE_4,  "e4heat,he4" },
    {PE_3,  "e5heat,he5" },
    
    {PE_8,  "fan0,fan" },
    {PF_9,  "fan1" },
    {PA_2,  "fan2" },
    {PA_1,  "fan3" },
    {PE_13,  "fan4" },
    {PB_11,  "fan5" },

    // Servo
    {PE_11,  "servo0" },

    //EXP1
    {PB_10, "PB10"},
    {PE_14, "PE14"},
    {PE_10, "PE10"},
    {PE_8, "PE8"},
    {PE_15, "PE15"},
    {PE_12, "PE12"},
    {PE_9, "PE9"},
    {PE_7, "PE7"},

    //EXP2
    {PB_14, "PB14"},
    {PB_13, "PB13"},
    {PC_5, "PC5"},
    {PC_4, "PC4"},
    {PF_11, "PF11"},
    {PB_15, "PB15"},
    {PB_2, "PB2"},

	//SD
	{PC_13, "SDCD"},
	{PC_9, "SDD1"},
	{PC_8, "SDD0"},
	{PC_12, "SDSCK"},
	{PD_2, "SDCMD"},
	{PC_11, "SDD3"},
	{PC_10, "SDD2"},

	// UART
	{PA_9, "TX1"},
	{PA_10, "RX1"},
};

constexpr BoardDefaults fly_f407zg_Defaults = {
    {0x8a5f5551, 0xd0c680ae},                   // Signatures
    SD_SDIO,                                    // SD Card access
    {   //CLK, MISO, MOSI
        {PA_5, PA_6, PA_7},                     //SPI0
        {PB_13, PB_14, PB_15},                  //SPI1
        {NoPin, NoPin, NoPin},                  //SPI2
        {PE_10, NoPin, PE_14},                  //SPI3
        {NoPin, NoPin, NoPin},                  //SPI4
        {NoPin, NoPin, NoPin},                  //SPI5
    },
	9,											// Number of drivers
    {PE_1, PG_12,  PD_7, PD_4,  PD_0, PG_8, PG_5, PG_2, PD_9},   	//enablePins
    {PB_9, PB_8, PA_8, PC_7,  PC_6, PD_15, PD_14, PD_13, PD_12},	//stepPins
    {PE_0, PG_11, PD_6, PD_3,  PA_15, PG_7, PG_4, PD_11, PD_8},    	//dirPins
#if HAS_SMART_DRIVERS
    {PG_13, PG_10, PD_5, PD_1,
#if STARTUP_DELAY
    // Avoid clash with jtag pins
    NoPin,
#else
    PA_14,
#endif
     PG_6, PG_3, PD_10, PB_12},                 //uartPins
    9,                                      	// Smart drivers
#endif
    0,                                       	//digiPot Factor
#if HAS_VOLTAGE_MONITOR
    NoPin,
#endif
    NoPin,
};


constexpr PinEntry PinTable_FLY_E3[] =
{
    //Thermistors
    {PA_4, "e0temp,t0"},
    {PA_3, "bedtemp,tb"},

    //Endstops
    {PA_2, "xmin,xstop"},
    {PA_1, "ymin,ystop"},
    {PC_5, "zmin,zstop"},

	// Servo
    {PB_0,  "servo0" },

   // Porbe
    {PC_4, "probe"},
	
    //Heaters and Fans (Big and Small Mosfets}
    {PA_0,  "bed,hbed" },
    {PA_5,  "e0heat,he0" },
    {PA_7,  "fan0,fan" },
    {PA_6,  "fan1" },



    //EXP1
    {PE_12, "beep"},
    {PE_11, "btnenc"},
    {PE_10, "btnen1"},
    {PE_9, "btnen2"},
    {PE_8, "lcdd4"},
    {PE_7, "lcdrs"},
    {PB_1, "lcden"},

	//SD
	{PA_15, "SDCD"},
	{PC_9, "SDD1"},
	{PC_8, "SDD0"},
	{PC_12, "SDSCK"},
	{PD_2, "SDCMD"},
	{PC_11, "SDD3"},
	{PC_10, "SDD2"},

	// UART
	{PA_9, "TX1"},
	{PA_10, "RX1"},

    // WIFI UART	
	{PD_8, "PD8"},
	{PD_9, "PD9"},	
	
    //WIFI
    {PE_13, "PE13"},
    {PE_14, "PE14"},
    {PE_15, "PE15"},

    //soft spi 
    {PC_0, "PC0"},
    {PC_1, "PC1"},
    {PC_2, "PC2"},
    {PC_3, "PC3"},
    {PC_7, "PC7"},

    //Signal light
     {PA_8, "PA8"},

    //FPC
    {PB_10, "FPC1"},
    {PB_11, "FPC2"},
    {PD_10, "FPC3"},
    {PD_11, "FPC4"},
    {PD_12, "FPC5"},
    {PD_13, "FPC6"},
    {PD_14, "FPC7"},
    {PD_15, "FPC8"},
    {PC_6, "FPC9"},
    {PD_0, "FPC10"},
    {PD_1, "FPC11"},


};

constexpr BoardDefaults fly_e3_Defaults = {
    {0xd0c680ae, 0xfd2146b0},                   // Signatures
    SD_SDIO,                                    // SD Card access
    {   //CLK, MISO, MOSI
        {PA_5, PA_6, PA_7},                     //SPI0
        {PB_13, PB_14, PB_15},                  //SPI1
        {NoPin, NoPin, NoPin},                  //SPI2
        {PC_2, PC_0, PC_1},                     //SPI3
        {PE_8, NoPin, PB_1},                    //SPI4
        {PD_6, PD_5, PD_4},                     //SPI5
    },
	4,											// Number of drivers
    {PC_15, PE_5, PE_1, PB_5},   	            //enablePins
    {PC_13, PE_3, PB_9, PB_3},	                //stepPins
    {PC_14, PE_4, PE_0, PB_4},    	            //dirPins
#if HAS_SMART_DRIVERS
    {PE_6, PE_2, PB_8, PD_7},                   //uartPins            
	4,                                          // Smart drivers
#endif
    0, 
#if HAS_VOLTAGE_MONITOR
    NoPin,
#endif
    NoPin,
};


constexpr PinEntry PinTable_FLY_CDYV2[] =
{
    //Thermistors
    {PA_3, "e0temp,t0"},
    {PC_4, "e1temp,t1"},
    {PC_5, "e2temp,t2"},
    {PB_1, "bedtemp,tb"},

    //Endstops
    {PC_7, "xmin,xstop"},
    {PC_6, "xmax,xstopmax"},
    {PD_11, "ymin,ystop"},
    {PD_10, "ymax,ystopmax"},
    {PB_10, "zmin,zstop"},
    {PB_11, "zmax,zstopmax"},

	// Servo
    {PE_6,  "servo0" },

   // Probe
    {PC_2, "probe"},
	
    //Heaters and Fans (Big and Small Mosfets}
    {PB_0,  "bed,hbed" },
    {PD_12,  "e0heat,he0" },
    {PD_13,  "e1heat,he1" },
    {PD_14,  "e2heat,he2" },
    {PA_0,  "fan0,fan" },
    {PA_1,  "fan1" },
    {PA_2,  "fan2" },


    //EXP1
    {PA_14, "lcdd7"},
    {PA_13, "lcdd6"},
    {PE_15, "lcdd4"},
    {PE_14, "lcdd5"},
    {PB_1, "lcden"},
	{PE_13, "tfcd"},

	//SD
//	{PC_9, "SDD1"},
//	{PC_8, "SDD0"},
//	{PC_12, "SDSCK"},
//	{PD_2, "SDCMD"},
//	{PC_11, "SDD3"},
//	{PC_10, "SDD2"},

	// UART
	{PA_9, "TX1,btnenc"},
	{PA_10, "RX1,lcdrs"},

    // WIFI UART	
	{PD_8, "PD8,btnen2"},
	{PD_9, "PD9,btnen1"},	
	
    //WIFI
    {PE_10, "PE10"},
    {PE_11, "PE11"},
    {PE_12, "PE12"},

    //spi 1  (SD,MAX311865,MAX6675)
    {PA_4, "PA4,SPI1SDCS"},
    {PA_5, "PA5,SPI1SCK"},
    {PA_6, "PA6,SPI1MISO"},
    {PA_7, "PA7,SPI1MOSI"},
    {PE_7, "PE7,SPI1CS1"},
    {PE_8, "PE8,SPI1CS2"},

    //spi 3  (MOT TMC2130 TMC5160)
    {PB_3, "PB3,MOTSCK"},
    {PB_4, "PB4,MOTMISO"},
    {PB_5, "PB5,MOTMOSI"},

    //Signal light   Neopixel
    {PD_15, "Neopixel,LED"},

    //Laser 
    {PB_9, "PB9,Laser"},
	
	//Power ADC
	{PC_3, "Power_ADC,PC3"}
};

constexpr BoardDefaults fly_cdyv2_Defaults = {
    {0x8a5f5551, 0xd0c680ae},                   // Signatures
    SD_SDIO,                                    // SD Card access
    {   //CLK, MISO, MOSI
        {PA_5, PA_6, PA_7},                     //SPI0
        {PB_13, PB_14, PB_15},                  //SPI1
        {PB_3, PB_4, PB_5},                     //SPI2
        {PE_15, NoPin, PB_2},                   //SPI3
        {NoPin, NoPin, NoPin},                  //SPI4
        {NoPin, NoPin, NoPin},                  //SPI5
    },
	6,											// Number of drivers
    {PC_1, PC_14, PB_8, PD_7, PD_4, PD_0},   	//enablePins
    {PE_5, PE_4, PE_3, PE_2, PE_1, PE_0},	    //stepPins
    {PC_0, PC_13, PB_7, PD_6, PD_3, PA_15},    	//dirPins
#if HAS_SMART_DRIVERS
    {PC_15, PA_8, PB_6, PD_5, PD_1, PE_9},      //uartPins      
	 6,                                       	// Smart drivers
#endif
    0,
#if HAS_VOLTAGE_MONITOR
    PC_3,
#endif
    NoPin,
};

constexpr PinEntry PinTable_FLY_E3_PRO[] =
{


    //Thermistors
    {PA_4, "e0temp,t0"},
    {PA_1, "e1temp,t1"},
    {PA_3, "bedtemp,tb"},
    {PC_1, "boardtemp,tboard"},
    //Endstops
    {PA_2, "xmin,xstop"},
    {PB_10, "ymin,ystop"},
    {PC_4, "zmin,zstop"},
    {PD_0, "e0min,e0stop"},
    {PD_1, "e1min,e1stop"},
	// Servo
    {PB_0,  "servo0" },

   // Porbe
    {PC_5, "probe"},
	
    //Heaters and Fans (Big and Small Mosfets}
    {PA_0,  "bed,hbed" },
    {PA_5,  "e0heat,he0" },
    {PC_6,  "e1heat,he1" },
    {PA_7,  "fan0,fan" },
    {PA_6,  "fan1" },
    {PB_6,  "fan2" },
    {PB_7,  "fan3" },

    //EXP1
    {PE_12, "beep"},
    {PE_11, "btnenc"},
    {PE_10, "btnen1"},
    {PE_9, "btnen2"},
    {PE_8, "lcdd4"},
    {PE_7, "lcdrs"},
    {PB_1, "lcden"},

	//SD

	{PC_9, "SDD1"},
	{PC_8, "SDD0"},
	{PC_12, "SDSCK"},
	{PD_2, "SDCMD"},
	{PC_11, "SDD3"},
	{PC_10, "SDD2"},

	// UART
	{PA_9, "TX1"},
	{PA_10, "RX1"},

    //Signal light
     {PA_8, "LED"},

    //FPC
    {PB_11, "neopixel"},
    {PD_11, "PSON"},
    {PE_6, "laser"},
    {PC_3, "Power_ADC"},
    {PD_10, "pwr, PWRDET"},

};

constexpr BoardDefaults fly_e3_pro_Defaults = {
	{0xd0c680ae},                   // Signatures
    SD_SDIO,                                    // SD Card access
    {   //CLK, MISO, MOSI
        {PA_5, PA_6, PA_7},                     //SPI0
        {PB_13, PB_14, PB_15},                  //SPI1
        {NoPin, NoPin, NoPin},                  //SPI2
        {PC_2, PC_0, PC_1},                     //SPI3
        {PE_8, NoPin, PB_1},                    //SPI4
        {PD_6, PD_5, PD_4},                     //SPI5
    },
    5,											// Number of drivers
    {PE_5, PE_1, PB_5, PD_6 ,PC_15},   	    //enablePins
    {PE_3, PB_9, PB_3, PD_4, PC_13},	    //stepPins
    {PE_2, PB_8, PD_7, PD_3, PC_0 },    	//dirPins
#if TMC_SOFT_UART
    {PE_4, PE_0, PB_4, PD_5, PC_14},           
	 5, 			                         //uartPins                                          	// Smart drivers
#endif
    0,  
#if HAS_VOLTAGE_MONITOR
    PC_3,
#endif
    NoPin,
};
#endif