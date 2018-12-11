#include "main.h"

/*Motor leftDrive(1, MOTOR_GEARSET_18, 0,  MOTOR_ENCODER_DEGREES);
Motor leftDrive1(2, MOTOR_GEARSET_18, 0, MOTOR_ENCODER_DEGREES);

Motor rightDrive(3, MOTOR_GEARSET_18, 1, MOTOR_ENCODER_DEGREES);
Motor rightDrive1(4, MOTOR_GEARSET_18, 1, MOTOR_ENCODER_DEGREES);

Motor rollers(6, MOTOR_GEARSET_18, 1, MOTOR_ENCODER_DEGREES);

static int slowBaseVelocity = 50;

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
*/
