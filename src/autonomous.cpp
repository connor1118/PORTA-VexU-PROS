#include "main.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
 bool red = true;
void mid()
{
  if(red)
  {
    shoot();
    drive(48);
    //intake(2000);
    drive(-78);
    turn(90);
    drive(10);
    driveHard(60);

  }
}


void autonomous() {

mid();

}
