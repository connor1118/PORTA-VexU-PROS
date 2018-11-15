#include "main.h"

Controller controller(CONTROLLER_MASTER);	//globally defined controller

void opcontrol() {
	while(true)
		{
			driveOP();
			intakeOP();
			shooterOP();
			delay(20);
		}
}
