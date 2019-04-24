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

ADIDigitalIn Park ('H');

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
  drive(15);
  stopIntake();
}

void skills()
{
  //shoot middle flag then align
  adjust(0);
  shoot();
  drive(-5);
  turn(-90);
  drive(-16);
  //get ball and flip cap
  drive(38);
  intakeDrive();
  intake();
  drive(-5);
  delay(1000);
  stopIntake();
  drive(5);
  flipDrive();
  //back up, align, and turn towards flags
  turn(-3);
  drive(-70);
  drive(-8);
  drive(15);
  turn(87);
  adjust(1);
  drive(55);
  //shoot next flag
  intake();
  delay(1500);
  stopIntake();
  shoot();
  //align for next cap
  drive(-3);
  turn(-90);
  drive(-10);
  drive(-10);
  //grab next ball and flip cap
  drive(40);
  intakeDrive();
  intake();
  drive(-5);
  delay(3000);
  stopIntake();
  drive(5);
  flipDrive();
  //turn and shoot
  drive(-8);
  turn(92);
  intake();
  drive(5);
  shoot();
  //hit bottom flag middle set
  turn(8);
  drive(46);
  drive(12);
  stopIntake();
  //back up and flip cap
  drive(-32);
  turn(90);
  drive(22);
  flipDrive();
  //turn diagonal and drive to align for park
  drive(-12);
  turn(45);
  drive(24);
  turn(45);
  drive(34);
  turn(90);
  drive(-20);
  //Park
  drive(26);
  intake();
  driveHard(35);
  drive(9);
  driveHard(36);
  brake();
  stopIntake();
  delay(500);
  coast();
}

void red()
{
  //grab ball and score cap
  drive(32);
  intakeDrive();
  //back up, align, and turn towards flags
  turn(-5);
  drive(-53);
  drive(-10);
  drive(9);
  turn(87);
  drive(7);
  //shoot top and middle flags
  intake();
  delay(250);
  stopIntake();
  shoot();
  delay(500);
  adjust(0);
  intake();
  delay(2000);
  stopIntake();
  shoot();
  //hit bottom flag
  turn(5);
  intake();
  drive(48);
  drive(4);
  //back up and wall align then flip cap
  turn(-1);
  drive(-30);
  turn(-90);
  drive(-12);
  delay(500);
  stopIntake();
  drive(24);
  flipDrive();
  //shoot middle flag
  drive(-5);
  turn(50);
  intake();
  delay(2000);
  shoot();
  //hit bottom middle flag
  drive(26);
  turn(15);
  drive(12);
  turn(25);
  drive(4);
  drive(-10);
  drive(12);
  drive(-12);
  //align for top flag and shoot
  turn(-35);
  drive(-30);
  adjust(1);
  delay(500);
  shoot();
  stopIntake();

  //park
  if(Park.get_value())
  {
    turn(-55);
    drive(-40);
    drive(-8);
    drive(45);
    turn(-90);
    intake();
    drive(31);
    driveHard(28);
    stopIntake();
    brake();
    delay(500);
    coast();
  }
}

void blue()
{
  //grab ball and score cap
  drive(32);
  intakeDrive();
  //back up, align, and turn towards flags
  turn(5);
  drive(-53);
  drive(-10);
  drive(9);
  turn(-87);
  drive(7);
  //shoot top and middle flags
  intake();
  delay(250);
  stopIntake();
  shoot();
  delay(500);
  adjust(0);
  intake();
  delay(2000);
  stopIntake();
  shoot();
  //hit bottom flag
  turn(-5);
  intake();
  drive(48);
  drive(4);
  //back up and wall align then flip cap
  turn(1);
  drive(-30);
  turn(90);
  drive(-12);
  delay(500);
  stopIntake();
  drive(24);
  flipDrive();
  //shoot middle flag
  drive(-5);
  turn(-50);
  intake();
  delay(2000);
  shoot();
  //hit bottom middle flag
  drive(26);
  turn(-15);
  drive(12);
  turn(-25);
  drive(4);
  drive(-10);
  drive(12);
  drive(-12);
  //align for top flag and shoot
  turn(35);
  drive(-30);
  adjust(1);
  delay(500);
  shoot();
  stopIntake();

  //park
  if(Park.get_value())
  {
    turn(50);
    drive(-40);
    drive(-8);
    drive(45);
    turn(90);
    intake();
    drive(31);
    driveHard(28);
    stopIntake();
    brake();
    delay(500);
    coast();
  }
}

void test()
{
  //drive(30);
  turn(90);
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
