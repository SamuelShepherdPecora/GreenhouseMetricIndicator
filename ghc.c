Can't create, edit, or upload … Not enough storage.
/**@brief Constants, structures, and function prototypes for Gh Control code
 * @file lab01.c
 * @version ceng153, serial: 8lf2f662
 */

#include "ghcontrol.h"


int main(void)
{
	time_t now;
	int logged;

	(unsigned)time(NULL);

	//void GhControllerInit(); //prints header

	struct readings creadings = {0};
	struct controls ctrl = {0};
	struct setpoints sets = {0};

	sets = GhSetTargets();

	while(1) //press any key to continue
	{
		time_t now;
		now = time(NULL);
		creadings = GhGetReadings();
		logged = GhLogData("ghdata.txt", creadings);
		GhDisplayReadings(creadings);
		GhDisplayTargets(sets);
		ctrl = GhSetControls(sets, creadings);
		GhDisplayControls(ctrl);
		GhDelay(GHUPDATE);

	}
		fprintf(stdout, "Press Enter to Continue...");
		fgetc(stdin);
		return EXIT_FAILURE;



}

