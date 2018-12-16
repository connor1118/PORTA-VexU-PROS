#include "main.h"
#include "base.hpp"
#include "intake.hpp"
/*Motor leftDrive(1, MOTOR_GEARSET_18, 0,  MOTOR_ENCODER_DEGREES);
Motor leftDrive1(2, MOTOR_GEARSET_18, 0, MOTOR_ENCODER_DEGREES);

Motor rightDrive(3, MOTOR_GEARSET_18, 1, MOTOR_ENCODER_DEGREES);
Motor rightDrive1(4, MOTOR_GEARSET_18, 1, MOTOR_ENCODER_DEGREES);

Motor rollers(6, MOTOR_GEARSET_18, 1, MOTOR_ENCODER_DEGREES);

static int slowBaseVelocity = 50;
static int medBaseVelocity = 100;

void intakeDrive(int inches)
{
  resetDrive();
  int distance = inches*(360/14.125);
  leftDrive.move_relative(distance, slowBaseVelocity);
  leftDrive1.move_relative(distance, slowBaseVelocity);
  rightDrive.move_relative(distance, slowBaseVelocity);
  rightDrive1.move_relative(distance, slowBaseVelocity);

  rollers.move_velocity(100);

  int dist = distance;
  while(!((leftDrive.get_position() < dist+3) && (leftDrive.get_position() > dist-3)))
  {
    delay(2);
  }
}

void capFlip(int inches)
{
  resetDrive();
  int distance = inches*(360/14.125);
  leftDrive.move_relative(distance, medBaseVelocity);
  leftDrive1.move_relative(distance, medBaseVelocity);
  rightDrive.move_relative(distance, medBaseVelocity);
  rightDrive1.move_relative(distance, medBaseVelocity);

  rollers.move_velocity(-200);

  int dist = distance;
  while(!((leftDrive.get_position() < dist+3) && (leftDrive.get_position() > dist-3)))
  {
    delay(2);
  }
}
*/
