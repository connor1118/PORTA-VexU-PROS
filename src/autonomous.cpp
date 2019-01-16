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

ADIDigitalIn A ('A');
ADIDigitalIn B ('B');
ADIDigitalIn C ('C');
ADIDigitalIn D ('D');

void flipDrive()
{
  flip();
  drive(20);
  stopFlip();
}

void intakeDrive()
{
  intake();
  drive(10);
  stopIntake();
}

void skills()
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

void red()
{
  drive(35);
  intakeDrive();
  drive(-55);
  drive(5);
  turn(-70);
  drive(8);
  shoot();
  delay(500);
  adjust(0);
  intake();
  delay(2000);
  stopIntake();
  shoot();
  turn(-1);
  intake();
  drive(50);
  turn(2);
  drive(-30);
  stopIntake();
  turn(45);
  shoot();
  turn(22);
  drive(10);
  flipDrive();
  turn(73);
  drive(32);
  driveHard(22);

}

void blue()
{
  shoot();
  turn(1);
  drive(48);
}

void test()
{
  adjust(0);
}

void autonomous() {

  shooterNoHold();

  if(A.get_value())
  {
    test();
  }
  if(B.get_value())
  {
    skills();
  }
  if(C.get_value())
  {
    red();
  }
  if(D.get_value())
  {
    blue();
  }



}
