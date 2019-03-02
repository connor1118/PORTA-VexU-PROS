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
  // shoot top flag, grab ball, flip cap
  shoot();
  drive(-4);
  turn(-90);
  drive(35);
  intakeDrive();
  intake();
  drive(-5);
  delay(1000);
  stopIntake();
  drive(5);
  flipDrive();
  //wall align, shoot middle flag
  turn(-10);
  drive(-75);
  drive(10);
  turn(90);
  drive(8);
  adjust(0);
  intake();
  delay(500);
  stopIntake();
  shoot();
  //hit bottom flag, flip second cap
  turn(10);
  intake();
  drive(48);
  drive(7);
  turn(-1);
  drive(-9);
  stopIntake();
  turn(-130);
  intake();
  delay(500);
  stopIntake();
  drive(22);
  flipDrive();
  //drive and hit bottom flag on middle set
  drive(-16);
  turn(47);
  drive(36);
  turn(90);
  drive(24);
  drive(10);// wall align on middle flags

  //drive and flip third cap
  drive(-32);
  flip();
  delay(200);
  stopFlip();
  turn(-95);
  drive(36);
  intake();
  delay(500);
  stopIntake();
  flipDrive();
  //turn and hit bottom flag on third set
  drive(-3);
  turn(90);
  drive(32);
  drive(10); //wall align 3rd flags
  //back up and shoot middle flag
  drive(-20);
  turn(8);
  drive(-34);
  delay(500);
  turn(-16);
  flip();
  delay(200);
  stopFlip();
  intake();
  delay(500);
  stopIntake();
  shoot();
  //aligning for park
  drive(-10);
  turn(-85);
  drive(26);
  drive(10); //wall align on blue wall
  drive(-20);
  turn(-90);
  drive(23);
  turn(-90);
  //parking
  intake();
  drive(6);
  driveHard(32);
  drive(8);
  driveHard(27);
  stopIntake();



}

void red()
{
  //grab ball and score cap
  drive(35);
  intakeDrive();
  //back up, align, and turn towards flags
  turn(-5);
  drive(-55);
  drive(9);
  turn(90);
  drive(7);
  //shoot top and middle flags
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
  drive(7);
  //back up and shoot flag from middle set
  turn(-1);
  drive(-30);
  stopIntake();
  turn(-70);
  shoot();
  //flip second cap
  turn(-25);
  drive(-12);
  drive(26);
  flipDrive();
  //align for park and park
  turn(-95);
  drive(32);
  driveHard(24);
}

void blue()
{
  //grab ball and score cap
  drive(35);
  intakeDrive();
  //back up, align, and turn towards flags
  turn(-5);
  drive(-55);
  drive(9);
  turn(-90);
  drive(7);
  //shoot top and middle flags
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
  drive(7);
  //back up and shoot flag from middle set
  turn(1);
  drive(-30);
  stopIntake();
  turn(70);
  shoot();
  //flip second cap
  turn(25);
  drive(-12);
  drive(26);
  flipDrive();
  //align for park and park
  turn(90);
  drive(32);
  driveHard(24);
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
