Can't create, edit, or upload … Not enough storage.
/** @brief Gh control functions
 *  @file ghcontrol.c
 */
#include "ghcontrol.h"



struct controls GhSetControls(struct setpoints target, struct readings rdata){

     struct controls cset;

	int ON = 1;
	int OFF = 0;


     if(rdata.temperature < target.temperature){
            cset.heater = ON;
    }
    else{
            cset.heater = OFF;
    }

    if(rdata.humidity < target.humidity){
            cset.humidifier = ON;
    }
    else{
            cset.humidifier = OFF;
    }
    return cset;
}

/** Prints Gh Controller Header
 *  @version ceng153, Serial:8lf2f662
 *  @author Samuel Shepherd-Pecora
 *  @since 2024-02-18
 *  @param sname string with Operator's name
 *  @return void
 */
void GhDisplayHeader(const char * sname)
{
	fprintf(stdout,"%s's CENG153 Greenhouse Controller\n",sname);
}


float dreads[]={0.0};

/** Delay in milliseconds
 *  @version ceng153, Serial:8lf2f662
 *  @author Samuel Shepherd-Pecora
 *  @since 2024-02-18
 *  @param miliseconds integer delay value
 *  @return void
 *
int GhLogData(char * fname, struct readings ghdata)
{
	FILE *fp;
	char ltime[CTIMESTRSZ];

	fp = fopen(fname, "a");

	if(fp == NULL){
		printf("Cannot open the file");
		return 0;
	}

	strncpy(ltime, ctime(&ghdata.rtime), 25);

	ltime[3] = ',';
	ltime[7] = ',';
	ltime[10] = ',';
	ltime[19] = ',';

	fprintf(fp, "\n%.24s, %5.1lf,%5.1lf, %6.1lf", ltime, ghdata.temperature, ghdata.humidity, ghdata.pressure);

	fclose(fp);
	return 1;
}
*/


/** Delay in milliseconds
 *  @version ceng153, Serial:8lf2f662
 *  @author Samuel Shepherd-Pecora
 *  @since 2024-02-18
 *  @param miliseconds integer delay value
 *  @return void
 *
int GhLogData(char * fname, struct readings ghdata)
{
	FILE *fp;
	char ltime[CTIMESTRSZ];

	fp = fopen(fname, "a");
	if(fp == NULL){
		printf("Cannot open the file");
		return 0;
	}

	strncpy(ltime, ctime(&ghdata.rtime), 25);

	ltime[3] = ',';
	ltime[7] = ',';
	ltime[10] = ',';
	ltime[19] = ',';

	fprintf(fp, "\n%.24s, %5.1lf,%5.1lf, %6.1lf", ltime, ghdata.temperature, ghdata.humidity, ghdata.pressure);

	fclose(fp);
	return 0;
}

*/


/** Logs data
 *  @version ceng153, Serial:8lf2f662
 *  @author Samuel Shepherd-Pecora
 *  @since 2024-03-10
 *  @param fname character pointer, readings strcuture ghdata tag
 *  @return void
 */
int GhLogData(char * fname, struct readings ghdata)
{
	FILE *fp;
	char ltime[CTIMESTRSZ];

	fp = fopen(fname, "a");
	if(fp == NULL){
		printf("Cannot open the file");
		return 0;
	}else{

	strncpy(ltime, ctime(&ghdata.rtime), 25);

	ltime[3] = ',';
	ltime[7] = ',';
	ltime[10] = ',';
	ltime[19] = ',';

	fprintf(fp, "\n%.24s, %5.1lf,%5.1lf, %6.1lf", ltime, ghdata.temperature, ghdata.humidity, ghdata.pressure);

	fclose(fp);
	return 1;
	}
}



/** Saves Setpoints
 *  @version ceng153, Serial:8lf2f662
 *  @author Samuel Shepherd-Pecora
 *  @since 2024-03-10
 *  @param setpoints structure spts tag, fname char pointer
 *  @return spts
 */

int GhSaveSetpoints(char * fname, struct setpoints spts)
{

	FILE *fp;
	
	fp = fopen(fname, "w");
	if(fp == NULL){
		return 0;
	}else
	{
		fwrite(&spts, 1 , sizeof(spts), fp);
		fclose(fp);
		return 1;
	}
}


/** Retrieves Setpoints
 *  @version ceng153, Serial:8lf2f662
 *  @author Samuel Shepherd-Pecora
 *  @since 2024-03-10
 *  @param fname char pointer
 *  @return spts
 */
struct setpoints GhRetrieveSetpoints(char * fname)
{
	struct setpoints spts = {0.0};
	FILE *fp = fopen(fname, "r");

	if(fp == NULL)
	{	
		printf("Cannot open the file");

		return spts;
	}else
	{
		fread(&spts, 1, sizeof(spts), fp);
		
		fclose(fp);

		return spts;
	}
}


/** Delay in milliseconds
 *  @version ceng153, Serial:8lf2f662
 *  @author Samuel Shepherd-Pecora
 *  @since 2024-02-18
 *  @param miliseconds integer delay value
 *  @return void
 */
void GhDelay(int milliseconds)
{
	long wait;
	clock_t now,start;

	wait = milliseconds *(CLOCKS_PER_SEC/1000);
	start = clock();
	now = start;
	while((now-start) < wait)
	{
		now = clock();
	}
}

/** Returns a random number in a given range
 *  @version ceng153, Serial:8lf2f662
 *  @author Samuel Shepherd-Pecora
 *  @since 2024-02-18
 *  @param range interger value of the range
 *  @return void
 */
int GhGetRandom(int range){
	return rand() % range;
}


//int GhSetVerticalBar(int bar, COLOR_SENSEHAT pxc, uint8_t value, struct fb_t *fb){
	
	//int i;
	
	
	



/** Greenhouse controller initializations
 *  @version ceng153, Serial:8lf2f662
 *  @author Samuel Shepherd-Pecora
 *  @since 2024-02-18
 *  @param none
 *  @return void
 */
void GhControllerInit(void){
	srand((unsigned)time(NULL));
	GhDisplayHeader("Samuel Shepherd-Pecora");

}

/** Prints out state of controls
 *  @version ceng153, Serial:8lf2f662
 *  @author Samuel Shepherd-Pecora
 *  @since 2024-02-18
 *  @param ctrl data source for printing out the controls
 *  @return void
 */
/**struct controls GhSetControls(struct setpoints target, struct readings rdata){

     if(rdata.temperature < cpoints.temperature){
            cset.heater = ON;
    }
    else{
            cset.heater = OFF;
    }

    if(rdata.humidity < cpoints.humidity){
            cset.humidifier = ON;
    }
    else{
            cset.humidifier = OFF;
    }
    return cset;
};
*/


/** Prints out readings
 *  @version ceng153, Serial:8lf2f662
 *  @author Samuel Shepherd-Pecora
 *  @since 2024-02-18
 *  @param rdata data of enviromental readings
 *  @return void
 */
void GhDisplayReadings(struct readings rdata){
	fprintf(stdout," \n%sReadings:\tT:%5.1fC\tH:%5.1f \tP:%6.1f\n", ctime(&rdata.rtime), rdata.temperature, rdata.humidity, rdata.pressure);

}

/** Prints out control targets
 *  @version ceng153, Serial:8lf2f662
 *  @author Samuel Shepherd-Pecora
 *  @since 2024-02-18
 *  @param none
 *  @return void
 */
void GhDisplayTargets(struct setpoints spts){
	fprintf(stdout,"Targets:  \tT:%5.1lfC\tH:%5.1lf",spts.temperature,spts.humidity);

	 /* struct setpoints cpoints;
    cpoints.temperature = STEMP;
    cpoints.humidity = SHUMID;
    return cpoints;*/

}

/** Gets temperature, humidity, and pressure readings
 *  @version ceng153, Serial:8lf2f662
 *  @author Samuel Shepherd-Pecora
 *  @since 2024-02-18
 *  @param none
 *  @return void
 */
struct readings GhGetReadings(void)
{
    struct readings now = {0};

    now.rtime = time(NULL);
    now.temperature = GhGetTemperature();
    now.humidity = GhGetHumidity();
    now.pressure = GhGetPressure();
    return now;
}

/** Prints controller controls
 *  @version ceng153, Serial:8lf2f662
 *  @author Samuel Shepherd-Pecora
 *  @since 2024-02-18
 *  @param target setpoints to heater and humidifier flag
 *  @param rdata data of enviromental readings
 *  @return void
 */
void GhDisplayControls(struct controls ctrl){

	int ON = 1;
	int OFF = 0;

    if(ctrl.heater){
        fprintf(stdout, "\nheater: %d", ON);
    }else
    {
        fprintf(stdout, "\nheater: %d", OFF);
    }

    if(ctrl.humidifier){
        fprintf(stdout, "\thumidifier: %d\n", ON);
    }else
    {
        fprintf(stdout, "\thumidifier: %d\n", OFF);
    }

}

/** Sets controller targets
 *  @version ceng153, Serial:8lf2f662
 *  @author Samuel Shepherd-Pecora
 *  @since 2024-02-18
 *  @param none
 *  @return void
 */
struct setpoints GhSetTargets(void){

	struct setpoints spts;
	struct setpoints cpoints;
	cpoints.temperature = STEMP;
 	cpoints.humidity = SHUMID;
	return cpoints;

	spts = GhRetrieveSetpoints("setpoints.dat");

	if(cpoints.temperature = 0){
	    
	    cpoints.temperature = STEMP;
	    cpoints.humidity = SHUMID;

	    GhSaveSetpoints("setpoints.dat", cpoints);
	}
	
	return cpoints;
}
	
	



/** Gets Humidity
 *  @version ceng153, Serial:8lf2f662
 *  @author Samuel Shepherd-Pecora
 *  @since 2024-02-18
 *  @param none
 *  @return void
 */
float GhGetHumidity(void){
#if SIMHUMIDITY
	return GhGetRandom(USHUMID - LSHUMID) + LSHUMID;
#else
	return 55;
#endif

}

/** Gets Pressure
 *  @version ceng153, Serial:8lf2f662
 *  @author Samuel Shepherd-Pecora
 *  @since 2024-02-18
 *  @param none
 *  @return void
 */
float GhGetPressure(void){

#if SIMPRESSURE
	return GhGetRandom(USPRESS - LSPRESS) + LSPRESS;
#else
	return 1013;
#endif
}

/** Gets temperature
 *  @version ceng153, Serial:8lf2f662
 *  @author Samuel Shepherd-Pecora
 *  @since 2024-02-18
 *  @param none
 *  @return void
 */
float GhGetTemperature(void){

#if SIMTEMPERATURE
	return GhGetRandom(USTEMP - LSTEMP) + LSTEMP;
#else
	return 20;
#endif

}
