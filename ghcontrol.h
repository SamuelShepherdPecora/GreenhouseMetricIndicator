Can't create, edit, or upload … Not enough storage.
/**brief Gh control constants, structures, function prototypes
 *  @file ghcontrol.h
 */
#ifndef GHCONTROL_H
#define GHCONTROL_H

//Includes
#include "led2472g.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "hts221.h"
#include "lps25h.h"



//Constants
#define GHUPDATE 2000
#define SENSORS 3
#define TEMPERATURE 0
#define HUMIDITY 1
#define PRESSURE 2
#define SIMULATE 1
#define USTEMP 50
#define LSTEMP -10
#define USHUMID 100
#define LSHUMID 0
#define USPRESS 1016
#define LSPRESS 975
#define STEMP 25.0
#define SHUMID 55.0
#define SIMTEMPERATURE 1
#define SIMHUMIDITY 1
#define SIMPRESSURE 1
#define CTIMESTRSZ 25
#define SENSEHAT 1

///@cond INTERNAL

//Structures
typedef struct readings{
    time_t rtime;
    float temperature;
    float humidity;
    float pressure;
}reading_s;

typedef struct setpoints{
    float temperature;
    float humidity;
}setpoints_s;

typedef struct controls{
    int heater;
    int humidifier;
}control_s;

struct controls GhSetControls(struct setpoints target, struct readings rdata);
struct setpoints GhSetTargets(void);
struct readings GhGetReadings(void);

//Function Prototypes
void GhDisplayHeader(const char * sname);
int GhGetRandom(int range);
int GhLogData(char * fname, struct readings ghdata);
int GhSetVerticalBar(int bar, COLOR_SENSEHAT pxc, uint8_t value, struct fb_t *fb);
void GhDelay(int milliseconds);
void GhControllerInit(void);
void GhDisplayControls(struct controls ctrl);
void GhDisplayReadings(struct readings rdata);
void GhDisplayTargets(struct setpoints spts);
//void GhGetReadings(float readings[SENSORS]);
//void GhSetControls(void);
//void GhSetTargets(void);


//floats
float GhGetHumidity(void);
float GhGetPressure(void);
float GhGetTemperature(void);
#endif

///@endcond
