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

void mid(bool red)
{
  if(red)
  {
    shoot();
    turn(-1);
    drive(48);
    //intake(2000);
  /*  drive(-28);
    turn(90);
    drive(12);
    flip();
    delay(1000);
    driveHard(6);
    delay(250);
    stopFlip();
    drive(-18);*/
    turn(1);
    drive(-79);
    turn(90);
    drive(10);
    driveHard(65);

  }
  else
  {
    flip();
    delay(1000);
    driveHard(6);
    delay(250);
    stopFlip();
  }
}


void autonomous() {

mid(1);

}
