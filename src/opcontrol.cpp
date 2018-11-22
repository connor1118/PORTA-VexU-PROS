#include "main.h"

Controller controller (CONTROLLER_MASTER);	//globally defined controller

void opcontrol() {
	while(true)
		{
			driveOP();
			intakeOP();
			shooterOP();

			if(controller.get_digital(DIGITAL_LEFT) && !competition::is_connected())
			{
			autonomous();
			}

			delay(20);
		}
}
