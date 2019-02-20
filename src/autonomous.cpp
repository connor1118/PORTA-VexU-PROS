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

void shortFlipDrive()
{
  flip();
  drive(10);
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
/*  shoot();
  drive(-1);
  turn(-90);
  drive(35);
  intakeDrive();
  intake();
  drive(-5);
  delay(1000);
  stopIntake();
  drive(5);
  flipDrive();
  drive(-75);
  drive(7);
  turn(90);
  drive(8);

  adjust(0);
  intake();
  delay(500);
  stopIntake();
  shoot();

  turn(3);
  intake();
  drive(45);
  drive(7);
  turn(-1);
  drive(-8);
  stopIntake();
  turn(-130);
  drive(22);
  flipDrive();
  drive(-16);
  turn(47);*/

  drive(34);
  turn(90);
  drive(24);
  drive(-42);
  intake();
  delay(500);
  stopIntake();
  shoot();
  drive(20);
  /*
  turn(-90);
  drive(12);
  flipDrive();
  turn(-90);
  drive(32);
  driveHard(22);
  turn(90);
  driveHard(35);*/
}

void red()
{
  drive(35);
  intakeDrive();
  drive(-55);
  drive(7);
  turn(90);
  drive(7);
  shoot();
  delay(500);
  adjust(0);
  intake();
  delay(2000);
  stopIntake();
  shoot();
  turn(3);
  intake();
  drive(46);
  turn(-1);
  drive(-30);
  stopIntake();
  turn(-60);
  shoot();
  turn(-35);
  drive(-5);
  drive(20);
  flipDrive();
  turn(-85);
  drive(32);
  driveHard(24);
}

void blue()
{
  drive(35);
  intakeDrive();
  drive(-55);
  drive(7);
  turn(-90);
  drive(7);
  shoot();
  delay(500);
  adjust(0);
  intake();
  delay(2000);
  stopIntake();
  shoot();
  turn(-3);
  intake();
  drive(46);
  turn(1);
  drive(-30);
  stopIntake();
  turn(60);
  shoot();
  turn(35);
  drive(-5);
  drive(20);
  flipDrive();
  turn(85);
  drive(32);
  driveHard(24);
}

void test()
{
  drive(60);
  //turn(90);
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
